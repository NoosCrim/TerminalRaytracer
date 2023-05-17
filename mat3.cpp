#include "vec3.h"
#include "mat3.h"
#include <cmath>
mat3::mat3(): m{0,0,0,0,0,0,0,0,0}
{

}
mat3::mat3(float _m[3][3]) : 
	m{
		{_m[0][0],_m[0][1], _m[0][2]},
		{_m[1][0],_m[1][1], _m[1][2]},
		{_m[2][0],_m[2][1], _m[2][2]}
	}
{

}
float* mat3::operator[](int i)
{
	return m[i];
}
vec3 mat3::operator*(vec3 v)
{
	return vec3(
		vec3(m[0][0], m[0][1], m[0][2]).Dot(v),
		vec3(m[1][0], m[1][1], m[1][2]).Dot(v),
		vec3(m[2][0], m[2][1], m[2][2]).Dot(v)
	);
}
mat3 mat3::operator*(mat3 b)
{
	mat3 result;
	result[0][0] = m[0][0] * b[0][0] + m[0][1] * b[1][0] + m[0][2] * b[2][0];
	result[0][1] = m[0][0] * b[0][1] + m[0][1] * b[1][1] + m[0][2] * b[2][1];
	result[0][2] = m[0][0] * b[0][2] + m[0][1] * b[1][2] + m[0][2] * b[2][2];	
	
	result[1][0] = m[1][0] * b[0][0] + m[1][1] * b[1][0] + m[1][2] * b[2][0];
	result[1][1] = m[1][0] * b[0][1] + m[1][1] * b[1][1] + m[1][2] * b[2][1];
	result[1][2] = m[1][0] * b[0][2] + m[1][1] * b[1][2] + m[1][2] * b[2][2];		
	
	result[2][0] = m[2][0] * b[0][0] + m[2][1] * b[1][0] + m[2][2] * b[2][0];
	result[2][1] = m[2][0] * b[0][1] + m[2][1] * b[1][1] + m[2][2] * b[2][1];
	result[2][2] = m[2][0] * b[0][2] + m[2][1] * b[1][2] + m[2][2] * b[2][2];

	return result;

}
mat3 mat3::RotX(float rad)
{
	float _m[3][3] = {
		{1, 0, 0},
		{0, cos(rad), -sin(rad)},
		{0, sin(rad), cos(rad)}
	};
	return mat3(_m);
}
mat3 mat3::RotY(float rad)
{
	float _m[3][3] = {
		{cos(rad), 0, sin(rad)},
		{0, 1, 0},
		{-sin(rad), 0, cos(rad)}
	};
	return mat3(_m);
}
mat3 mat3::RotZ(float rad)
{
	float _m[3][3] = {
		{cos(rad), -sin(rad), 0},
		{sin(rad), cos(rad), 0},
		{0, 0, 1}
	};
	return mat3(_m);
}
mat3 mat3::Rot(vec3 v, float rad)
{

	float _cos = cos(rad), _sin = sin(rad);
	float _m[3][3] = {
		{ v.x * v.x * (1 - _cos) + _cos, v.y * v.x * (1 - _cos) - v.z * _sin, v.z * v.x * (1 - _cos) + v.y * _sin },
		{ v.x * v.y * (1 - _cos) + v.z * _sin, v.y * v.y * (1 - _cos) + _cos, v.z * v.y * (1 - _cos) - v.x * _sin },
		{ v.x * v.z * (1 - _cos) - v.y * _sin, v.y * v.z * (1 - _cos) + v.x * _sin, v.z * v.z * (1 - _cos) + _cos }
	};
	return mat3(_m);
}