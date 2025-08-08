#pragma once
#include "geometry.hpp"
class triangle : public geometry
{
public:
	triangle(const vec3& v0, const vec3& v1, const vec3& v2) : v0{ v0 }, v1{ v1 }, v2{ v2 } {}
	triangle(const vec3& v0, const vec3& v1, const vec3& v2, const vec3& n0, const vec3& n1, const vec3& n2)
		:v0{ v0 }, v1{ v1 }, v2{ v2 }, n0{ n0 }, n1{ n1 }, n2{ n2 } {}
	bool hit(const ray& r, float t_min, float t_max, hit_info& record) const override;


private:
	
	vec3 v0, v1, v2;//position fo triangle
	vec3 n0, n1, n2;//face normals
};

