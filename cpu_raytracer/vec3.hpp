#pragma once
#include <cmath>
class vec3
{
public:
	vec3(float x, float y, float z) :xyz{ x,y,z } {}
	vec3() : xyz{ 0,0,0 } {}

	//operators
	float operator[](int n) const { return xyz[n]; }
	float& operator[] (int n) { return xyz[n]; }
	vec3 operator-() { return vec3{ -xyz[0],-xyz[1],-xyz[2]}; }

	//functions
	float length() const { return std::sqrt(length_squared()); }
	float length_squared() const { return xyz[0] * xyz[0] + xyz[1] * xyz[1] + xyz[2] *xyz[2]; }

private:
	float xyz[3];
};

//typedef
typedef vec3 point3;

//inline functions
inline vec3 operator*(float t, const vec3& v)
{
	return vec3{ v[0] * t,v[1] * t,v[2] * t };
}
inline vec3 operator*(const vec3& v, float t)
{
	return t * v;
}
inline vec3 operator/(const vec3& v, float t)
{
	return (1 / t) * v;
}
inline vec3 operator+(const vec3& v, const vec3& u)
{
	return vec3{ v[0] + u[0],v[1] + u[1],v[2] + u[2] };
}
inline vec3 normalize(const vec3& v)
{
	return v / v.length();
}
inline vec3 cross(const vec3& v, const vec3& u)
{
	return vec3{ v[1] * u[2] - v[2] * u[1],v[2] * u[0] - v[0] * u[2],v[0] * u[1] - v[1] * u[0] };
}
inline float dot(const vec3& v, const vec3& u)
{
	return v[0] * u[0] + v[1] * u[1] + v[2] * u[2];
}


