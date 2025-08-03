#pragma once
#include "ray.hpp"
#include <vector>
class camera
{
public:
	 camera() {}
	 void render();

	//we will be able to set settings by accessing public members
	unsigned int image_width;
	float apect_ratio;
	point3 look_from{0,0,0};
	vec3 vector_up{ 0,1,0 };
	point3 look_at{ 0,0,-1 };
	float vfov = 90;
private:

	void init();
	void get_ray(int x, int y) const;
	void save_to_png();

	float focal_length;
	unsigned int image_height;
	vec3 u, v, w;//camera basis
	float pixel_delta_v, pixel_delta_h;//difference between pixels;
	float viewport_height;
	float viewport_width;
	point3 camera_center;
	//used for writing data to file. Will be later reserved as heightXwidthX3
	std::vector<uint8_t>frame_buffer;

};

