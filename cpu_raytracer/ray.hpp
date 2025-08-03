#pragma once
#include "vec3.hpp"
class ray
{
public:
	ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}
	ray() : ray(point3{ 0,0,0 }, vec3{ 0,0,0 }) {}

	point3 at(float t) const;
	const vec3& direction() const;
	const point3 origin() const;
private:
	point3 orig;
	vec3 dir;
};

