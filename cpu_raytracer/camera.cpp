#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "camera.hpp"
#include <algorithm>
#include <iostream>
#include "world.hpp"
void camera::render(const world& w)
{
	init();
	frame_buffer.resize(image_height * image_width * 3);

	//main render loop
	for (int j = 0;j < image_height;j++)
	{
		for (int i = 0; i < image_width;i++)
		{
			ray curr_ray = get_ray(i, j);
			vec3 color = pixel_color(curr_ray,w);


			//preprocess data : gamma correction, clamp, writing to buffer;
			float r = std::sqrt(color[0]);
			float g = std::sqrt(color[1]);
			float b = std::sqrt(color[2]);

			uint8_t ir = static_cast<uint8_t>(256 * std::clamp(r, 0.000f, 0.999f));
			uint8_t ig = static_cast<uint8_t>(256 * std::clamp(g, 0.000f, 0.999f));
			uint8_t ib = static_cast<uint8_t>(256 * std::clamp(b, 0.000f, 0.999f));

			int index = (j * image_width + i) * 3;
			frame_buffer[index + 0] = ir;
			frame_buffer[index + 1] = ig;
			frame_buffer[index + 2] = ib;


		}
	}
}

void camera::init()
{
	image_height = int(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;
	auto theta = degrees_to_radians(vfov);
	auto h = std::tan(theta / 2);
	focal_length = (look_from - look_at).length();
	auto viewport_height = 2 * h * focal_length;
	auto viewport_width = viewport_height * (double(image_width) / image_height);
	camera_center = look_from;

	w = normalize(look_from - look_at);
	u = normalize(cross(vector_up, w));
	v = cross(w, u);

	vec3 viewport_h = viewport_width * u;
	vec3 viewport_v = viewport_height * -v;
	pixel_delta_h = viewport_h / image_width;
	pixel_delta_v = viewport_v / image_height;


	point3 upper_left_corner = camera_center - (focal_length * w) - viewport_h / 2 - viewport_v / 2;
	pixel00_loc = upper_left_corner + 0.5 * (pixel_delta_h + pixel_delta_v);

	
}

ray camera::get_ray(int x, int y) const
{
	point3 pixel = pixel00_loc + x * pixel_delta_h + y * pixel_delta_v;
	auto dir = pixel - camera_center;
	return ray{ camera_center,dir };
}

void camera::save_to_png(const char* name) const
{
	//stbi_flip_vertically_on_write(true);
	if (!stbi_write_png(name, image_width, image_height, 3, frame_buffer.data(), image_width * 3))
	{
		std::cerr << "Could not save image to file!\n";
		std::cout << "hit something" << "\n";
	}
}

vec3 camera::pixel_color(const ray& r, const world& scene) const
{
	hit_info hi;
	if (scene.hit(r, 0.001, infinity, hi))
	{
		return 0.5 * (hi.normal + vec3{ 1,1,1 });

	}
	vec3 unit_direction = normalize(r.direction());
	float t = 0.5f * (unit_direction[1] + 1.0f);  


	return (1.0f - t) * vec3 { 1.0f, 1.0f, 1.0f } + t * vec3{ 0.5f, 0.7f, 1.0f };
}
