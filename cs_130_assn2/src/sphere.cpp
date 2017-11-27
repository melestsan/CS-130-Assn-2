#include "sphere.h"
#include "ray.h"


// Determine if the ray intersects with the sphere
bool Sphere::Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
    vec3 w = ray.direction;
    vec3 u = ray.endpoint;
    vec3 v = u - center;
    
    double dis = pow(dot(w, v), 2) - dot(w, w) * (dot(v, v) - pow(radius,2));
    
    if(dis < 0) {
		return false;
	}
	
	if(dis == 0) {
		return true;
	}
    
    if(dis > 0) {
		return true;
	}
    
    return false;
}

vec3 Sphere::Normal(const vec3& point) const
{
    vec3 normal;
    // TODO: set the normal
    return normal;
}
