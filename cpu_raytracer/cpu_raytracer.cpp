#include "camera.hpp"
#include <iostream>
#include "model.hpp"
int main()
{
    camera cam;
    cam.image_width = 1280;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.look_from = { 0, 0, -3 };
    cam.look_at = { 0, 0, 0 };
    cam.vector_up = { 0, 1, 0 };
    cam.vfov = 60;

    world w;

    model m("models/suzanne.obj");
    if (!m.load_model_world(w)) {
        std::cerr << "Failed to load model.\n";
        return 1;
    }

    cam.render(w);
    cam.save_to_png("render.png");
}
