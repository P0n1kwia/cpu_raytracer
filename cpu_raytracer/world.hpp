#pragma once
#include "geometry.hpp"
#include <memory>
#include <vector>
class world : public geometry
{
public:
	world() {}
	void add(const  std::shared_ptr<geometry> obj) { objects.push_back(obj); }
	bool hit(const ray& r, float t_min, float t_max, hit_info& record) const override
	{
		hit_info temp;
		float closest_so_far = t_max;
		bool hit_anything = false;
		for (const auto& obj : objects)
		{
			if (obj->hit(r, t_min, closest_so_far, temp))
			{
				hit_anything = true;
				closest_so_far = temp.t;
				record = temp;
			}
		}
		return hit_anything;

	}

	std::vector<std::shared_ptr<geometry>> objects;
};