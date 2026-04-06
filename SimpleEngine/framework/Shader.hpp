#ifndef SHADER_HPP__
#define SHADER_HPP__

#include <string>

class Shader {
    unsigned int shaderProgram;
    
public:
    Shader(const char *vertexShader, const char *fragmentShader);
    void use();
    
    void setFloat(const std::string &name, float v1);
    void setFloat(const std::string &name, float v1, float v2, float v3);
    void setFloat(const std::string &name, float v1, float v2, float v3, float v4);
};

#endif
