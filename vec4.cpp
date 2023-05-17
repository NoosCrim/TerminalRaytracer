#include "vec4.h"
#include <cmath>
vec4::vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w)
{

}

float vec4::Dot(const vec4& v) const
{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}
float vec4::LengthSquared() const
{
	return x * x + y * y + z * z + w * w;
}
float vec4::Length() const
{
	return sqrt(LengthSquared());
}
vec4 vec4::Normalized() const
{
	return *this / this->Length();
}

vec4 vec4::operator+(const vec4& v) const
{
	return vec4(v.x + x, v.y + y, v.z + z, v.w + w);
}
vec4 vec4::operator-(const vec4& v) const
{
	return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}
vec4 vec4::operator/(const float& s) const
{
	return vec4(x / s, y / s, z / s, w / s);
}
vec4 vec4::operator*(const float& s) const
{
	return vec4(x * s, y * s, z * s, w * s);
}
vec4 vec4::operator-() const
{
	return vec4(-x, -y, -z, -w);
}
vec4 operator*(const float& s, const vec4& v)
{
	return vec4(v.x * s, v.y * s, v.z * s, v.w * s);
}
vec4 operator/(const float& s, const vec4& v)
{
	return vec4(v.x / s, v.y / s, v.z / s, v.w / s);
}