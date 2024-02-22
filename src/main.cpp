#include "World.h"
#include<iostream>
#include<map>
#include<array>
 std::map<std::string, std::vector<double>> COLORS;


void initializeColorMap(){
    COLORS["red"] = std::vector<double>{		23.5137,	0.5760,	0.3387};
    COLORS["green"] = std::vector<double>{	49.9823,	0.3659,	0.5476};
    COLORS["blue"] = std::vector<double>{	8.3958,	0.1858,	0.1819};
    COLORS["black"] = std::vector<double>{0.0000,	0.0000,	0.0000};
    COLORS["white"] = std::vector<double>{	100.0000,	0.3127,	0.3290};
}
std::vector<double> selectColor(){
        int n;
        std::cout << "Select color (Red (0), Green (1) ,Blue (2), Black(3), White(4))\n";
        std::cin >> n;
        while(n < 0 || n > 4){
            std::cout << "Wrong number. Select color (Red (0), Green (1) ,Blue (2), Black(3), White(4))\n";
            std::cin >> n;
        }
        std::vector<double> _color(3);
        switch(n){
            case 0 : 
                _color = COLORS["red"];
                break;
            case 1:
                _color = COLORS["green"];
                 break;
            case 2:
                _color = COLORS["blue"];
                 break;
            case 3:
                _color = COLORS["black"];
                 break;
            case 4:
                 _color = COLORS["red"];
                 break;
              
        }

        return _color;
        
    }

int main(){

    initializeColorMap();
    std::cout <<"Type number of spheres\n";
    int number_of_spheres;
    std::cin >> number_of_spheres;
    int i = 1;
    World world;
    for(int i = 0; i < number_of_spheres ; i++){
        std::cout << "Creating " << i + 1 <<  "/" << number_of_spheres << "spheres\n";
        std::cout << "Type center position\n";

        std::vector<double> p(3);
        std::cout <<"x coordinate : ";
        std::cin >> p[0];
        std::cout <<"\ny coordinate : ";
        std::cin >> p[1];
        std:: cout << "\nz coordinate : ";
        std::cin >> p[2];

        std:: cout << "\nType radius\n";
        double radius;
        std::cin >> radius;

        std::cout << "Type material ('lambertian (1)', 'dialectric (2)', 'metal (3)') \n";
        int code;
        std::cin >> code;
        while( code < 1 || code > 3){
            std::cout << "Wrong number. Type material ('lambertian (1)', 'dialectric (2)', 'metal (3)') \n";
            std::cin >> code;
        }

        if(code == 1){
            std::vector<double> color = selectColor();
            world.addHittableLambertianObject(p,radius,color);
        }else if (code == 2){
            double fuzz;
            std::cout << "Type fuzz: ";
            std::cin >> fuzz;
            std::cout <<"\n";
            world.addHitattableDialectricObject(p,radius,fuzz);
        }   
        else{
            std::vector<double> color = selectColor();
            double fuzz;
            std::cout << "Type fuzz: ";
            std::cin >> fuzz;
            std::cout <<"\n";
            world.addHittableMetalObject(p,radius,color,fuzz);
        }



    }

    world.printWorld();
    return 0;

}
