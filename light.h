#pragma once
#include "vec3.h"
class light
{
public:
	float intensity;
	light(float _intensity = 1);
	virtual vec3 LightHitDirection(vec3 hitPoint) = 0;
	virtual float ValueAtPoint(vec3 hitPoint) = 0;
};
class point_light : public light
{
public:
	point_light(vec3 _pos, float _intensity, float _fade);
	vec3 LightHitDirection(vec3 p);
	float ValueAtPoint(vec3 p);
	vec3 pos;
	float fade;
};