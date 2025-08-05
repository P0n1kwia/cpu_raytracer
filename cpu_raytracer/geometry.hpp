#pragma once
#include "ray.hpp"
struct hit_info
{
	vec3 normal; // normal
	point3 p; // point of intersection
	float t; // parameter t at which we hit target
	bool front_face; // what is a direction of normal. We want outward normals
	float u, v, w; //barycentric coordinates for triangles
	void set_normal(const vec3& ray_dir, const vec3& outward_normal)
	{
		front_face = dot(ray_dir, outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
		normal = normalize(normal);
	}
};
class geometry
{
public:
	virtual bool hit(const ray& r, float t_min, float t_max, hit_info& record) const = 0;
	virtual ~geometry() = default;
};