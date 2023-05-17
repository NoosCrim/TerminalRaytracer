#include "light.h"
#include "vec3.h"
#include <iostream>
light::light(float _intensity): intensity(_intensity)
{

}
point_light::point_light(vec3 _pos, float _intensity, float _fade): 
	pos(_pos), light(_intensity), fade(_fade)
{
	
}
vec3 point_light::LightHitDirection(vec3 p)
{
	return (pos - p).Normalized();
}
float point_light::ValueAtPoint(vec3 p)
{
	return intensity / (1.f + (p - pos).LengthSquared() * fade);
}