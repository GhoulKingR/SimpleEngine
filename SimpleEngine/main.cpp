//
//  main.cpp
//  SimpleEngine
//
//  Created by Chigozie Oduah on 04/04/2026.
//

#include <iostream>
#include "framework/BaseApplication.hpp"

class Applicaton : public BaseApplication {
public:
    Applicaton() : BaseApplication("Using my engine", 800, 600) {}
    ~Applicaton() {
        for (Object *obj : objects) {
            delete obj;
        }
    }
    
    void init() override {
        Object *triangle = new Object;
        triangle->verties = {
            0.5f, 0.5f, 0.0f,
            0.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
        };
        objects.push_back(triangle);
        
        triangle = new Object;
        triangle->verties = {
            -0.5f,  0.5f, 0.0f,
             0.0f,  0.0f, 0.0f,
            -1.0f,  0.0f, 0.0f,
        };
        objects.push_back(triangle);
    }
};

int main(int argc, const char * argv[]) {
    return Applicaton().start();
}
