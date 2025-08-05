#include "camera.hpp"
#include "world.hpp"
#include "triangle.hpp"
int main()
{
    vec3 v0(-2, -1, -5);
    vec3 v1(1, -1, -5);
    vec3 v2(0, 1, -5);

    // camera setup
    camera cam;
    cam.image_width = 1280;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.look_from = { 0, 0, 0 };
    cam.look_at = { 0, 0, -1 };
    cam.vector_up = { 0, 1, 0 };
    cam.vfov = 90;

    // world (scene)
    world w;
    w.add(std::make_shared<triangle>(
        vec3{ -0.5, 0, -1.0 },//v0
        vec3{ 0.5, 0, -1.0 },//v1
        vec3{ 0.0, 1, -1.0 }//v2
    ));

    cam.render(w);
    cam.save_to_png("Pierwszy_render.png");

    return 0;
   
    return 0;
}
