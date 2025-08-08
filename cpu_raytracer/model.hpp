#pragma once
#include "tiny_obj_loader.h"
#include "triangle.hpp"
#include <memory>
#include "world.hpp"
class model 
{
public:
	
	bool load_model_world(world& w);
	model(const std::string& filepath) : filepath(filepath) {}

private:
	std::vector<std::shared_ptr<triangle>> triangles;
	std::string filepath;
	vec3 get_vertex(const tinyobj::attrib_t& attrib, int ind);
	vec3 get_normal(const tinyobj::attrib_t& attrib, int ind);
};

