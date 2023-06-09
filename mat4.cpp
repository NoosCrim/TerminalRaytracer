#include "vec4.h"
#include "mat4.h"
#include "vec3.h"
#include <cmath>
mat4::mat4() : m{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
{

}
mat4::mat4(float _m[4][4]) :
	m{
		_m[0][0], _m[0][1], _m[0][2], _m[0][2],
		_m[1][0], _m[1][1], _m[1][2], _m[1][2],
		_m[2][0], _m[2][1], _m[2][2], _m[2][2],
		_m[3][0], _m[3][1], _m[3][2], _m[3][2]
	}
{

}
float* mat4::operator[](int i)
{
	return m[i];
}
vec4 mat4::operator*(vec4 v)
{
	return vec4(
		vec4(m[0][0], m[0][1], m[0][2], m[0][3]).Dot(v),
		vec4(m[1][0], m[1][1], m[1][2], m[1][3]).Dot(v),
		vec4(m[2][0], m[2][1], m[2][2], m[2][3]).Dot(v),
		vec4(m[3][0], m[3][1], m[3][2], m[3][3]).Dot(v)
	);
}
mat4 mat4::operator*(mat4 b)
{
	float _m[4][4] = {
		{
			m[0][0] * b[0][0] + m[0][1] * b[1][0] + m[0][2] * b[2][0] + m[0][3] * b[3][0],
			m[0][0] * b[0][1] + m[0][1] * b[1][1] + m[0][2] * b[2][1] + m[0][3] * b[3][1],
			m[0][0] * b[0][2] + m[0][1] * b[1][2] + m[0][2] * b[2][2] + m[0][3] * b[3][2],
			m[0][0] * b[0][3] + m[0][1] * b[1][3] + m[0][2] * b[2][3] + m[0][3] * b[3][3]
		},
		{
			m[1][0] * b[0][0] + m[1][1] * b[1][0] + m[1][2] * b[2][0] + m[1][3] * b[3][0],
			m[1][0] * b[0][1] + m[1][1] * b[1][1] + m[1][2] * b[2][1] + m[1][3] * b[3][1],
			m[1][0] * b[0][2] + m[1][1] * b[1][2] + m[1][2] * b[2][2] + m[1][3] * b[3][2],
			m[1][0] * b[0][3] + m[0][1] * b[1][3] + m[1][2] * b[2][3] + m[1][3] * b[3][3]
		},
		{
			m[2][0] * b[0][0] + m[2][1] * b[1][0] + m[2][2] * b[2][0] + m[2][3] * b[3][0],
			m[2][0] * b[0][1] + m[2][1] * b[1][1] + m[2][2] * b[2][1] + m[2][3] * b[3][1],
			m[2][0] * b[0][2] + m[2][1] * b[1][2] + m[2][2] * b[2][2] + m[2][3] * b[3][2],
			m[2][0] * b[0][3] + m[2][1] * b[1][3] + m[2][2] * b[2][3] + m[2][3] * b[3][3]
		},
		{
			m[3][0] * b[0][0] + m[3][1] * b[1][0] + m[3][2] * b[2][0] + m[3][3] * b[3][0],
			m[3][0] * b[0][1] + m[3][1] * b[1][1] + m[3][2] * b[2][1] + m[3][3] * b[3][1],
			m[3][0] * b[0][2] + m[3][1] * b[1][2] + m[3][2] * b[2][2] + m[3][3] * b[3][2],
			m[3][0] * b[0][3] + m[3][1] * b[1][3] + m[3][2] * b[2][3] + m[3][3] * b[3][3]
		}
	};
	return mat4(_m);
}
mat4 mat4::RotX(float rad)
{
	float _m[4][4] = {
		{ 1, 0, 0, 0 },
		{ 0, cos(rad), -sin(rad), 0 },
		{ 0, sin(rad), cos(rad), 0 },
		{ 0, 0, 0, 1 }
	};
	return mat4(_m);
}
mat4 mat4::RotY(float rad)
{
	float _m[4][4] = {
		{ cos(rad), 0, -sin(rad), 0 },
		{ 0, 1, 0, 0 },
		{ sin(rad), 0, cos(rad), 0 },
		{ 0, 0, 0, 1 }
	};
	return mat4(_m);
}
mat4 mat4::RotZ(float rad)
{
	float _m[4][4] = {
		{ cos(rad), -sin(rad), 0, 0 },
		{ sin(rad), cos(rad), 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 }
	};
	return mat4(_m);
}
mat4 mat4::Rot(vec3 v, float rad)
{

	float _cos = cos(rad), _sin = sin(rad);
	float _m[4][4] = {
		{ v.x * v.x * (1 - _cos) + _cos, v.y * v.x * (1 - _cos) - v.z * _sin, v.z * v.x * (1 - _cos) + v.y * _sin, 0 },
		{ v.x * v.y * (1 - _cos) + v.z * _sin, v.y * v.y * (1 - _cos) + _cos, v.z * v.y * (1 - _cos) - v.x * _sin, 0 },
		{ v.x * v.z * (1 - _cos) - v.y * _sin, v.y * v.z * (1 - _cos) + v.x * _sin, v.z * v.z * (1 - _cos) + _cos, 0 },
		{ 0, 0, 0, 1 }
	};
	return mat4(_m);
}
mat4 mat4::Translate(vec3 v)
{
	float _m[4][4] = {
		{ 1, 0, 0, v.x },
		{ 0, 1, 0, v.y },
		{ 0, 0, 1, v.z },
		{ 0, 0, 0, 1 }
	};
	return mat4(_m);
}
