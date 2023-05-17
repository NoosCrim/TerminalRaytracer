#pragma once
class vec4;
class vec3;
class mat4
{
private:
	float m[4][4];
public:
	mat4();
	mat4(float _m[4][4]);
	float* operator[](int i);
	vec4 operator*(vec4 v);
	mat4 operator*(mat4 b);
	static mat4 RotX(float rad);
	static mat4 RotY(float rad);
	static mat4 RotZ(float rad);
	static mat4 Rot(vec3 v, float rad);
	static mat4 Translate(vec3 v);
};
