//
//  Object.hpp
//  SimpleEngine
//
//  Created by Chigozie Oduah on 04/04/2026.
//

#ifndef OBJECT_HPP__
#define OBJECT_HPP__

#include "Shader.hpp"
#include <vector>
#include <array>
#include <optional>

class Object {
private:
    unsigned int VBO = 0;
    unsigned int VAO = 0;
    static std::optional<Shader> defaultShader;
    void init();
    void render();
    
public:
    Object();
    std::vector<float> verties;
    std::array<float, 3> translate = {0.0, 0.0, 0.0};
    std::array<float, 4> color = {1.0, 1.0, 1.0, 1.0};
    float rotation = 0;

    friend class BaseApplication;
};

#endif
