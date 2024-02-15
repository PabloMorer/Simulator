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

       inline void addHittableObject(){

        
            auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
            list.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

            auto material1 = make_shared<dielectric>(1.5);
            list.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

            auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
            list.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

            auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
            list.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));
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