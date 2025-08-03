#pragma once
#include "ray.hpp"
#include <vector>
class camera
{
public:
	 camera() {}
	 void render();
	 void save_to_png(const char* name) const;
	//we will be able to set settings by accessing public members
	int image_width = 100;
	float aspect_ratio = 16.0/9.0;
	point3 look_from{0,0,0};
	vec3 vector_up{ 0,1,0 };
	point3 look_at{ 0,0,-1 };
	float vfov = 90;
private:

	void init();
	ray get_ray(int x, int y) const;
	
	vec3 pixel_color(const ray& r) const;
	float focal_length = 1.0;
	int image_height;
	vec3 u, v, w;//camera basis
	vec3 pixel_delta_v, pixel_delta_h;//difference between pixels;
	point3 camera_center;
	point3 pixel00_loc;
	//used for writing data to file. Will be later reserved as height*width*3
	std::vector<uint8_t>frame_buffer;

};

