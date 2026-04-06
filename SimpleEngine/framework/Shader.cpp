#include "Shader.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <sstream>
#include <fstream>
#include <iostream>

Shader::Shader(const char *vertexShader, const char *fragmentShader) {
    std::ifstream vShaderFile,   fShaderFile;
    std::string   vShaderSource, fShaderSource;
    
    // ensure they can throw exceptions
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    
    try {
        vShaderFile.open(vertexShader);
        fShaderFile.open(fragmentShader);
        
        std::stringstream vStream, fStream;
        vStream << vShaderFile.rdbuf();
        fStream << fShaderFile.rdbuf();
        
        vShaderSource = vStream.str();
        fShaderSource = fStream.str();
    } catch (const std::ifstream::failure &e) {
        fprintf(stderr, "Error reading shader files: %s\n", e.what());
    }
    
    const char *vShaderCode = vShaderSource.c_str();
    const char *fShaderCode = fShaderSource.c_str();
    
    // compile vertex shader
    unsigned int vertID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertID, 1, &vShaderCode, NULL);
    glCompileShader(vertID);
    
    // error checking vertex shader
    int success;
    char infoLog[512];
    glGetShaderiv(vertID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertID, 512, NULL, infoLog);
        fprintf(stderr, "Error compiling vertex shader: %s\n", infoLog);
    }
    
    // compile fragment shader
    unsigned int fragID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragID, 1, &fShaderCode, NULL);
    glCompileShader(fragID);
    
    // error checking fragment shader
    glGetShaderiv(fragID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragID, 512, NULL, infoLog);
        fprintf(stderr, "Error compiling fragment shader: %s\n", infoLog);
    }
    
    // link both shaders into a program
    shaderProgram =  glCreateProgram();
    glAttachShader(shaderProgram, vertID);
    glAttachShader(shaderProgram, fragID);
    glLinkProgram(shaderProgram);
    
    // error checking for shader program
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        fprintf(stderr, "Error linking shader program: %s\n", infoLog);
    }
    
    glDeleteShader(vertID);
    glDeleteShader(fragID);
}

void Shader::use() {
    glUseProgram(shaderProgram);
}

void Shader::setFloat(const std::string &name, float v1) {
    glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), v1);
}

void Shader::setFloat(const std::string &name, float v1, float v2, float v3) {
    glUniform3f(glGetUniformLocation(shaderProgram, name.c_str()), v1, v2, v3);
}

void Shader::setFloat(const std::string &name, float v1, float v2, float v3, float v4) {
    glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), v1, v2, v3, v4);
}
