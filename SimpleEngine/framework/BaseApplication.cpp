//
//  BaseApplication.cpp
//  SimpleEngine
//
//  Created by Chigozie Oduah on 04/04/2026.
//

#include "BaseApplication.hpp"

BaseApplication::BaseApplication(const char *title, int screenWidth, int screenHeight) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    window = glfwCreateWindow(screenWidth, screenHeight, title, NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

int BaseApplication::start() {
    init();
    
    for (Object *obj : objects) {
        obj->init();
    }
    
    // render loop
    while (!glfwWindowShouldClose(window)) {
        loop();
        
        // clear screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // render objects
        for (Object *obj : objects) {
            obj->render();
        }
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    return EXIT_SUCCESS;
}
