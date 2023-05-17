#include "camera.h"
#include "object.h"
#include <float.h>
#include <thread>
#include <vector>
#include <iostream>
#include <cmath>
ray::ray(const vec3& _anchor, const vec3& _direction): anchor(_anchor), direction(_direction.Normalized())
{

}
void ray::SetDirection(vec3 v)
{
	direction = v.Normalized();
}
vec3 ray::GetDirection() const
{
	return direction;
}
ray ray::Reflection(const vec3& anchor, const vec3& normal) const
{
	return ray(anchor, direction - 2 * direction.Dot(normal) * normal);
}

float ray::CalculateValue(light** LSB, int LSBsize, object** OB, int OBsize, float defaultVal, float ambient, float specularRange, float specularStrenght, int reflectionsLeft) const
{
	float minDistance = FLT_MAX;
	vec3 xPos;
	int nearestXobjIndex = -1;
	for (int i = 0; i < OBsize; i++)
	{
		float distance;
		vec3 newX;
		if(OB[i]->RayIntersection(*this, newX, distance))
			if (distance < minDistance)
			{
				minDistance = distance;
				xPos = newX;
				nearestXobjIndex = i;
			}
	}
	if (nearestXobjIndex == -1)
		return defaultVal;
	return OB[nearestXobjIndex]->CalculateValueAtX(*this, xPos, minDistance, LSB, LSBsize, OB, OBsize, specularRange, specularStrenght, ambient, defaultVal, reflectionsLeft);
}

camera::camera(vec3 _pos, vec3 _up, vec3 _right, int _w, int _h, int _paletteSize, const char* _palette):
	pos(_pos), up(_up.Normalized()), right(_right.Normalized()), fwd(Cross(_up, _right).Normalized()), displayWidth(_w), displayHeight(_h), 
	PALETTE_SIZE(_paletteSize), PALETTE(_palette), displayString(new char[(_w+1)*_h])
{
	for (int i = 0; i < displayHeight - 1; i++)
		(*this)[i][displayWidth] = '\n';
	(*this)[displayHeight - 1][displayWidth] = '\0';
}

char* camera::operator[](int row)
{
	return &displayString[(row) * (displayWidth + 1)];
}
char camera::ReadPalette(float f) const
{
	int index = (int)round(f * (PALETTE_SIZE - 1));
	//std::cout << f << ": " << index << '\n';
	return PALETTE[index];
}
void camera::EvalPixel(int row, int collumn, object** OB, int OBsize, light** LSB, int LSBsize, float defaultValue, float ambient, float specularRange, float specularStrenght, int reflections)
{
	ray r = GetPixelRay(row, collumn);
	(*this)[row][collumn] = ReadPalette(r.CalculateValue(LSB, LSBsize, OB, OBsize, defaultValue, ambient, specularRange, specularStrenght, reflections));
}
void camera::Render(object** OB, int OBsize, light** LSB, int LSBsize, float defaultValue, float ambient, float specularRange, float specularStrenght, int reflections)
{
	std::vector<std::thread> pixelEvals;
	for (int row = 0; row < displayHeight; row++)
		for (int collumn = 0; collumn < displayWidth; collumn++)
			pixelEvals.push_back(std::thread(&camera::EvalPixel, this, row, collumn, OB, OBsize, LSB, LSBsize, defaultValue, ambient, specularRange, specularStrenght, reflections));
	for (std::thread& _thread : pixelEvals)
		_thread.join();
}
void camera::Display() const
{
	std::puts(displayString);
}

camera::~camera()
{
	delete displayString;
}
perspectiveCameraFlat::perspectiveCameraFlat(vec3 _pos, vec3 _up, vec3 _right, int _w, int _h, float cameraPlaneWidth, float cameraPlaneHeight, int _paletteSize, const char* _palette) :
	camera(_pos, _up, _right, _w, _h, _paletteSize, _palette), planeHeight(cameraPlaneHeight), planeWidth(cameraPlaneWidth)
{

}
ray perspectiveCameraFlat::GetPixelRay(int row, int collumn)
{
	return ray(pos, ((planeWidth * (float)collumn / displayWidth - planeWidth / 2) * right + (planeHeight * (float)row / displayHeight - planeHeight / 2) * up + fwd));
}


