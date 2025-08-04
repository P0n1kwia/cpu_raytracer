#pragma once
#include "geometry.hpp"
class triangle : public geometry
{
public:
	triangle(const vec3& v0, const vec3& v1, const vec3& v2) : v0{ v0 }, v1{ v1 }, v2{ v2 } { u = v = w = 0; }
	bool hit(const ray& r, float t_min, float t_max, hit_info& record) const override;

private:
	float u, v, w; //barycentric coordinates
	vec3 v0, v1, v2;//position fo triangle
};

