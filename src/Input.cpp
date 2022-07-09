//
// Created by van den Brand on 09/07/2022.
//

#include "Input.h"
#include "GameHandler.h"

namespace input {

    GLFWwindow *window;
    GameHandler *game;

    void initialize(GLFWwindow *window, GameHandler &game) {
        input::window = window;
        input::game = &game;
    }

    void handleKeyEvent(GLFWwindow *window, int key, int scancode, int action, int mods) {
        // Check if a game is active
        if (game != nullptr) {
            // Send the key event to the game
            if (action == GLFW_PRESS || action == GLFW_REPEAT)
                game->onKeyDown(key);
            else if (action == GLFW_RELEASE)
                game->onKeyUp(key);
        }
    }

    bool isKeyDown(int key) {
        return glfwGetKey(window, key);
    }
}
