#include "triangle.hpp"

bool triangle::hit(const ray& r, float t_min, float t_max, hit_info& record) const
{
	vec3 v0v1 = v1 - v0;
	vec3 v0v2 = v2 - v0;
	vec3 normal = cross(v0v1, v0v2);
	vec3 rcv0v2 = cross(r.direction(), v0v2);
	double det = dot(v0v1, rcv0v2);
	if (fabs(det) < epsilon) return false;

	double inv_det = 1.0 / det;

	vec3 T = r.origin() - v0;
	vec3 Q = cross(T, v0v1);
	double t = inv_det * dot(Q, v0v2);
	if (t<t_min || t>t_max) return false;
	record.p = r.at(t);
	record.t = t;

	record.u = inv_det * dot(rcv0v2, T);

	if (record.u < 0 || record.u > 1) return false;

	record.v = inv_det * dot(Q, r.direction());
	if (record.v < 0 || record.u + record.v> 1) return false;

	record.w = 1 - record.u - record.v;
	record.set_normal(r.direction(), normalize(normal));
	
	return true;
    


}
