#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"

#define max(a, b) ((a > b) ? a : b)

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth) const
{
    vec3 color;
    // TODO: determine the color
    
    //vec3 ambient; 
    vec3 diffuse;
    vec3 specular;
    
    vec3 light_color;
    vec3 inter_to_light;
    vec3 reflected_direction;
    
    //ambient = world.ambient_color * world.ambient_intensity * color_ambient;
    
    for(unsigned i  = 0; i < world.lights.size(); i++) {
		inter_to_light = world.lights[i]->position - intersection_point;
		light_color = world.lights[i]->Emitted_Light(ray) / 
		              inter_to_light.magnitude_squared();
		diffuse = color_diffuse * light_color * 
				  max(dot(inter_to_light.normalized(), same_side_normal.normalized()), 0);   
				  
		reflected_direction = (2 * 
							   dot(inter_to_light.normalized(), same_side_normal) * 
							   (same_side_normal - inter_to_light.normalized())).normalized();
	    specular = color_specular * pow(max(dot(reflected_direction, world.camera.position), 0), specular_power) * 
				   max(dot(inter_to_light.normalized(), same_side_normal.normalized()), 0);   
	}
  
	color = diffuse + specular;
    
    return color;
}
