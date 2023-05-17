#include "object.h"
#include "camera.h"
#include "light.h"
#include <iostream>
vertex::vertex(vec3 _pos, vec3 _normal, float _brightness, float _reflectiveness): pos(_pos), normal(_normal), brightness(_brightness), reflectiveness(_reflectiveness)
{

}

triangle::triangle(vertex _a, vertex _b, vertex _c): a(_a), b(_b), c(_c)
{

}

float triangle::CalculateSpecular(light* LS, float specularRange, float specularStrenght, const ray& r, const vec3& xPos, const vec3& xNormal) const
{
	float cos = LS->LightHitDirection(xPos).Dot(-r.GetDirection());
	float value = (cos - specularRange) / (1.f - specularRange) * specularStrenght * LS->intensity;
	return value > 0 ? value : 0;
}

float triangle::CalculateDiffuse(light* LS, const vec3& xPos, const vec3& xNormal, float xBrightness) const
{
	vec3 lightDir = LS->LightHitDirection(xPos);
	float cos = lightDir.Dot(xNormal);
	cos = cos > 0 ? cos : 0;
	return (cos + 1)/2 * LS->ValueAtPoint(xPos) * xBrightness;
}

bool triangle::CheckShadow(light* LS, object** OB, int OBsize, const vec3& xPos) const
{
	ray lightRay(xPos, - (LS->LightHitDirection(xPos)));
	vec3 v;
	float f;
	float d ;
	for (int i = 0; i < OBsize; i++)
		if (OB[i] != this)
		{
			if (OB[i]->RayIntersection(lightRay, v, f))
				return true;
		}
		else 

			
	return false;
}

vertex triangle::Interpolate(vec3 p) const
{
	float t = Cross(b.pos - a.pos, c.pos - a.pos).LengthSquared();
	float Wa = sqrt(Cross(b.pos - p, c.pos - p).LengthSquared() / t),
		  Wb = sqrt(Cross(b.pos - p, c.pos - p).LengthSquared() / t);
	float Wc = 1.f - Wa - Wb;
	vec3 newNormal = a.normal * Wa + b.normal * Wb + c.normal * Wc;
	return vertex(
		p, 
		newNormal.Normalized(),
		a.brightness * Wa + b.brightness * Wb + c.brightness * Wc, 
		a.reflectiveness * Wa + b.reflectiveness * Wb + c.reflectiveness * Wc);
}

bool triangle::RayIntersection(const ray& r, vec3& outIntersection, float& outDistance) const
{
	//check winding
	vec3 tNormal = (b.pos - a.pos).Cross(c.pos - a.pos).Normalized();
	float rtNormalDot = tNormal.Dot(r.GetDirection());
	if (rtNormalDot >= 0.f)
		return false;
	float naDot = tNormal.Dot(a.pos);
	float distance = (naDot - tNormal.Dot(r.anchor)) / tNormal.Dot(r.GetDirection());
	vec3 intersection = r.anchor + r.GetDirection() * distance;
	if ((c.pos - b.pos).Cross(intersection - b.pos).Dot(tNormal) > -0.0001f && (b.pos - a.pos).Cross(intersection - a.pos).Dot(tNormal) > -0.0001f && (a.pos - c.pos).Cross(intersection - c.pos).Dot(tNormal) > -0.0001f && distance > 0)
	{
		outDistance = distance;
		outIntersection = intersection;
		return true;
	}
	return false;
}

float triangle::CalculateValueAtX(const ray& r, vec3 xPos, float xDistance, light** LSB, int LSBsize, object** OB, int OBsize, float specularRange, float specularStrenght, float ambient, float  defaltValue, int reflectionsLeft) const
{
	float outValue;
	vertex xVertex = Interpolate(xPos);
	float specular = 0, diffuse = 0, reflection = 0;

	for (int LSBindex = 0; LSBindex < LSBsize; LSBindex++)
	{
		if (!CheckShadow(LSB[LSBindex], OB, OBsize, xVertex.pos))
		{
			specular += CalculateSpecular(LSB[LSBindex], specularRange, specularStrenght, r, xVertex.pos, xVertex.normal);
			diffuse += CalculateDiffuse(LSB[LSBindex], xVertex.pos, xVertex.normal, xVertex.brightness);
		}
	}

	if (reflectionsLeft > 0)
	{
		ray reflectionRay = r.Reflection(xVertex.pos, xVertex.normal);
		reflection = reflectionRay.CalculateValue(LSB, LSBsize, OB, OBsize, defaltValue, ambient, specularRange, specularStrenght, reflectionsLeft - 1) * xVertex.reflectiveness;
		diffuse = diffuse * (1.f - xVertex.reflectiveness);
		outValue = specular + diffuse + reflection + ambient * xVertex.brightness;
	}

	else
	{
		outValue = specular + diffuse + ambient * xVertex.brightness;
	}
	if (specular != specular)
		std::cout << "specular\n";
	if (diffuse != diffuse)
		std::cout << "diffuse\n";
	if (reflection != reflection)
		std::cout << "reflection\n";
	if (ambient * xVertex.brightness < 0)
		std::cout << "ambient\n";
	if (outValue > 1)
		outValue = 1;
	return outValue;
}