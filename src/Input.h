//
// Created by van den Brand on 09/07/2022.
//

#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include "GameHandler.h"

namespace input {

    void initialize(GLFWwindow *window, GameHandler &game);

    void handleKeyEvent(GLFWwindow *window, int key, int scancode, int action, int mods);

    /**
     * Checks whether a key is currently pressed.
     * @param key key to be checked
     * @return true if the given key is down
     */
    bool isKeyDown(int key);
}

#endif
