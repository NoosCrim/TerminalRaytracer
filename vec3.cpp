#include "vec3.h"
#include <cmath>
vec3::vec3(float _x, float _y, float _z):x(_x), y(_y), z(_z)
{

}

float vec3::Dot(const vec3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}
vec3 vec3::Cross(const vec3& v) const 
{
	return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x };
}
float vec3::LengthSquared() const
{
	return x * x + y * y + z * z;
}
float vec3::Length() const
{
	return sqrt(LengthSquared());
}
vec3 vec3::Normalized() const
{
	return *this / this->Length();
}

vec3 vec3::operator+(const vec3& v) const
{
	return vec3(v.x + x, v.y + y, v.z + z);
}
vec3 vec3::operator-(const vec3& v) const
{
	return vec3(x - v.x, y - v.y, z - v.z);
}
vec3 vec3::operator/(const float& s) const
{
	return vec3(x / s, y / s, z / s);
}
vec3 vec3::operator*(const float& s) const
{
	return vec3(x * s, y * s, z * s);
}
vec3 vec3::operator-() const
{
	return vec3(-x, -y, -z);
}

vec3 Cross(const vec3& a, const vec3& b)
{
	return a.Cross(b);
}

vec3 operator*(const float& s, const vec3& v)
{
	return vec3(v.x * s, v.y * s, v.z * s);
}
vec3 operator/(const float& s, const vec3& v)
{
	return vec3(v.x / s, v.y / s, v.z / s);
}