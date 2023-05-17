#pragma once
class vec3;
class mat3
{
private:
	float m[3][3];
public:
	mat3();
	mat3(float _m[3][3]);
	float* operator[](int i);
	vec3 operator*(vec3 v);
	mat3 operator*(mat3 b);
	static mat3 RotX(float rad);
	static mat3 RotY(float rad);
	static mat3 RotZ(float rad);
	static mat3 Rot(vec3 v, float rad);
};

