#pragma once
#include "tiny_obj_loader.h"
#include "triangle.hpp"
#include <memory>
class model : public geometry
{
public:
	bool hit(const ray& r, float t_min, float t_max, hit_info& record) const override;
	model(const std::string& file_path);

private:

	std::vector<std::unique_ptr<triangle>> triangles;

	
};

