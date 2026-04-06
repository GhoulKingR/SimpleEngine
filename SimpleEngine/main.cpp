//
//  main.cpp
//  SimpleEngine
//
//  Created by Chigozie Oduah on 04/04/2026.
//

#include <iostream>
#include <numbers>
#include "framework/BaseApplication.hpp"

class Applicaton : public BaseApplication {
public:
    Applicaton() : BaseApplication("Using my engine", 800, 800) {}
    
    void init() override {
        Object *triangle = new Object;
        triangle->verties = {
            0.0f,  0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
        };
        objects["first"] = triangle;
        
        Object *t2 = new Object;
        t2->verties = {
            0.0f,  0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
        };
        objects["second"] = t2;
        
        triangle->rotation = 45 * (std::numbers::pi / 180);
        triangle->translate = {-0.25, 0, 0};
        triangle->color = {0, 1, 0, 0.5};
        
        t2->translate = {0.25, 0, -0.1};
        t2->color = {1, 0, 0, 0.5};
    }
};

int main(int argc, const char * argv[]) {
    return Applicaton().start();
}
