#pragma once
class vec3
{
public:
	float x, y, z;
	vec3(float _x = 0, float _y = 0, float _z = 0);

	float Dot(const vec3& v) const;
	vec3 Cross(const vec3& v) const;
	float LengthSquared() const;
	float Length() const;
	vec3 Normalized() const;

	vec3 operator+(const vec3& v) const;
	vec3 operator-(const vec3& v) const;
	vec3 operator/(const float& v) const;
	vec3 operator*(const float& v) const;
	vec3 operator-() const;
};
vec3 Cross(const vec3& a, const vec3& b);

vec3 operator*(const float& s, const vec3& v);
vec3 operator/(const float& s, const vec3& v);
