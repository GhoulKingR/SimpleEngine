//
//  Object.cpp
//  SimpleEngine
//
//  Created by Chigozie Oduah on 04/04/2026.
//
#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Object.hpp"

std::optional<Shader> Object::defaultShader;

Object::Object() {
    if (!defaultShader.has_value()) {
        defaultShader.emplace(
            "/Users/chigozieoduah/Desktop/default_shaders/default.vs",
            "/Users/chigozieoduah/Desktop/default_shaders/default.fs"
        );
    }
}

void Object::init() {
    // generate vertex buffer objects
    glGenBuffers(1, &VBO);
    
    // Generate Vertex array objects
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    // copy data from vectors to buffer
    const float* ptr = verties.data();
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verties.size() * sizeof(float), ptr, GL_STATIC_DRAW);
    
    // set vertex attributes pointers and unbind
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Object::render() {
    defaultShader.value().use();
    defaultShader.value().setFloat("translate", translate[0], translate[1], translate[2]);
    defaultShader.value().setFloat("outColor", color[0], color[1], color[2], color[3]);
    defaultShader.value().setFloat("rotate", rotation);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
