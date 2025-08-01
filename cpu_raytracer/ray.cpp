#include "ray.hpp"

point3 ray::at(float t) const
{
    return orig + t * dir;
}

const vec3& ray::direction() const
{
    return dir;
}

const point3 ray::origin() const
{
    return orig;
}
