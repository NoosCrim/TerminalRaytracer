#pragma once
class vec4
{
public:
	float x, y, z, w;
	vec4(float _x = 0, float _y = 0, float _z = 0, float _w = 0);

	float Dot(const vec4& v) const;
	float LengthSquared() const;
	float Length() const;
	vec4 Normalized() const;

	vec4 operator+(const vec4& v) const;
	vec4 operator-(const vec4& v) const;
	vec4 operator/(const float& v) const;
	vec4 operator*(const float& v) const;
	vec4 operator-() const;
};
vec4 operator*(const float& s, const vec4& v);
vec4 operator/(const float& s, const vec4& v);