#pragma once
#include "vec3.h"
class light;
class ray;
class object
{
	virtual float CalculateSpecular(light* LS, float specularRange, float specularStrenght, const ray& r, const vec3& xPos, const vec3& xNormal) const = 0;
	virtual float CalculateDiffuse(light* LS, const vec3& xPos, const vec3& xNormal, float xBrightness) const = 0;
	virtual bool CheckShadow(light* LS, object** OB, int OBsize, const vec3& xPos) const = 0;
public:
	virtual bool RayIntersection(const ray& r, vec3& outIntersection, float& outDistance) const = 0;
virtual float CalculateValueAtX(const ray& r, vec3 xPos, float xDistance, light** LSB, int LSBsize, object** OB, int OBsize, float specularRange, float specularStrenght, float ambient, float  defaltValue, int reflectionsLeft) const = 0;
};
class vertex
{
public:
	vertex(vec3 _pos, vec3 _normal, float _brightness, float _reflectiveness);
	vec3 pos, normal;
	float brightness, reflectiveness;
};
class triangle : public object
{
	float CalculateSpecular(light* LS, float specularRange, float specularStrenght, const ray& r, const vec3& xPos, const vec3& xNormal) const;
	float CalculateDiffuse(light* LS, const vec3& xPos, const vec3& xNormal, float xBrightness) const;
	bool CheckShadow(light* LS, object** OB, int OBsize, const vec3& xPos) const;
public:
	vertex a,b,c;
	triangle(vertex _a, vertex _b, vertex _c);
	vertex Interpolate(vec3 p) const;
	bool RayIntersection(const ray& r, vec3& outIntersection, float& outDistance) const;
	float CalculateValueAtX(const ray& r, vec3 xPos, float xDistance, light** LSB, int LSBsize, object** OB, int OBsize, float specularRange, float specularStrenght, float ambient, float  defaltValue, int reflectionsLeft) const;
};
