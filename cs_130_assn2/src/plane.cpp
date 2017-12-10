#include "plane.h"
#include "ray.h"
#include <cfloat>


// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
bool Plane::
Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
	double t_1;
	
    vec3 w = ray.direction;
    vec3 u = ray.endpoint;
    
    t_1 = -dot(normal, (u - x1)) / dot(normal,w);

	if(t_1 < 0) {
		return false;
	}
	
	Hit h1 = {this, t_1, true};
	
	hits.push_back(h1);
	return true;
	
}

vec3 Plane::
Normal(const vec3& point) const
{
    return normal;
}
