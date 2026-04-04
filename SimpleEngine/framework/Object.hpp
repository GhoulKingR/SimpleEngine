//
//  Object.hpp
//  SimpleEngine
//
//  Created by Chigozie Oduah on 04/04/2026.
//

#ifndef OBJECT_HPP__
#define OBJECT_HPP__

#include <vector>

class Object {
private:
    unsigned int VBO;
    unsigned int VAO;
    unsigned int shaderProgram;
    
    void init();
    void render();
    void compileShaders();
    
public:
    std::vector<float> verties;

    friend class BaseApplication;
};

#endif
