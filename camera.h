#pragma once
#include "vec3.h"
class light;
class object;
class ray
{
protected:
	vec3 direction;
public:
	vec3 anchor;
	void SetDirection(vec3 v);
	vec3 GetDirection() const;
	ray Reflection(const vec3& anchor, const vec3& normal) const;
	float CalculateValue(light** LSB, int LSBsize, object** OB, int OBsize, float defaultVal, float ambient, float specularRange, float specularStrenght, int reflectionsLeft) const;
	ray(const vec3& _anchor, const vec3& _direction);
};
class camera
{
protected:
	const int PALETTE_SIZE;
	const char* PALETTE;
	char* displayString;
public:
	vec3 pos, up, right, fwd;
	const int displayWidth, displayHeight;
	camera(vec3 _pos, vec3 _up, vec3 _right, int _w, int _h, int _paletteSize = 42, const char* _palette = " .,:;^+<il!t?I[{1jrcoaxznumbOkhXQ8&Z0#MWB@");
	virtual ray GetPixelRay(int row, int collumn) = 0;
	char* operator[](int row);
	char ReadPalette(float f) const;
	void EvalPixel(int row, int collumn, object** OB, int OBsize, light** LSB, int LSBsize, float defaultValue, float ambient, float specularRange, float specularStrenght, int reflections);
	void Render(object** OB, int OBsize, light** LSB, int LSBsize, float defaultValue, float ambient, float specularRange, float specularStrenght, int reflections);
	void Display() const;
	~camera();
};
class perspectiveCameraFlat : public camera
{
public:
	const float planeWidth, planeHeight;
	perspectiveCameraFlat(vec3 _pos, vec3 _up, vec3 _right, int _w, int _h, float cameraPlaneWidth, float cameraPlaneHeight, int _paletteSize = 42, const char* _palette = " .,:;^+<il!t?I[{1jrcoaxznumbOkhXQ8&Z0#MWB@");
	ray GetPixelRay(int row, int collumn);
};