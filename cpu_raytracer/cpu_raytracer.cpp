#include "camera.hpp"
#include "world.hpp"
int main()
{
   
    //camera setup
    camera cam;
    cam.image_width = 1280;
    cam.aspect_ratio = 16.0 / 9.0;
    //world(scene) setup
    world w;

    //render and save
    cam.render(w);
    cam.save_to_png("Pierwszy_render.png");
   
    return 0;
}
