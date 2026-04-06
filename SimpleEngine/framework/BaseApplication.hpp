//
//  BaseApplication.h
//  SimpleEngine
//
//  Created by Chigozie Oduah on 04/04/2026.
//
#ifndef BASE_APPLICATION_HPP__
#define BASE_APPLICATION_HPP__

#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <unordered_map>
#include <string>
#include "Object.hpp"

class BaseApplication {
private:
    GLFWwindow *window = NULL;
    
protected:
    std::unordered_map<std::string, Object*> objects;
    
    // user defined functions
    virtual void init(){}
    virtual void loop(){}
public:
    BaseApplication(const char *title, int screenWidth, int screenHeight);
    ~BaseApplication();
    int start();
};

#endif
