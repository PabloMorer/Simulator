#ifndef WORLD_H
#define WORLD_H

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"
#include "color.h"
#include "camera.h"

class World {
    public:
        World(){};
        World(hittable_list _list){
            this->list = _list;
        }
        ~World(){};
       inline void addHittableList(hittable_list _list){
         this->list = _list;
       }
       inline void addHitattableDialectricObject(std::vector<double> point, double radius, double fuzz){
                    point3 p(point);
                    auto material = make_shared<dielectric>(fuzz);
                    list.add(make_shared<sphere>(p, radius, material));
       }
       
       inline void addHittableLambertianObject(std::vector<double> point, double radius, std::vector<double> _color){
                    point3 p(point);
                    color c(_color);
                    auto material = make_shared<lambertian>(c);
                    list.add(make_shared<sphere>(p, radius, material));     
       }

       inline void addHittableMetalObject(std::vector<double> point, double radius, std::vector<double> _color, double fuzz ){
                    point3 p(point);
                    color c(_color);
                    auto material = make_shared<metal>(c, fuzz);
                    list.add(make_shared<sphere>(p, radius, material));
       }

       inline void printWorld(){
            camera cam;
            cam.aspect_ratio = 16.0 / 9.0;
            cam.image_width =  1200;
            cam.samples_per_pixel = 500;
            cam.max_depth = 50;

            cam.vfov     = 20;
            cam.lookfrom = point3(13,2,3);
            cam.lookat   = point3(0,0,0);
            cam.vup      = vec3(0,1,0);

            cam.defocus_angle = 0.6;
            cam.focus_dist    = 10.0;

            cam.render(this->list);
       }

    private:
        hittable_list list;
    
};


#endif