#include "sphere.h"
#include "ray.h"


// Determine if the ray intersects with the sphere
bool Sphere::Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
	double t_1;
	double t_2;
	
    vec3 w = ray.direction;
    vec3 u = ray.endpoint;
    vec3 v = u - center;
    
    double dis = pow(dot(w, v), 2) - (dot(v, v) - pow(radius,2));
    
    if(dis < 0) {
		return false;
	}
	
	if(dis == 0) {
		t_1 = -dot(w,v) + sqrt(dis);
		
		Hit h1 = {this, t_1, true};
		
		hits.push_back(h1);
		return true;
	}
    
    if(dis > 0) {
		t_1 = -dot(w,v) + sqrt(dis);
		t_2 = -dot(w,v) - sqrt(dis);
		
		Hit h1 = {this, t_1, true};
		Hit h2 = {this, t_2, true};
		
		hits.push_back(h1);
		hits.push_back(h2);
		
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
