#include "camera.hpp"
int main()
{
    camera cam;
    cam.image_width = 800;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.render();
    cam.save_to_png("Pierwszy_render.png");
   
    
}
