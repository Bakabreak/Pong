#include <GLFW/glfw3.h>
#include <chrono>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <iomanip>

const int WINDOW_WIDTH = 1500, WINDOW_HEIGHT = 900;
const int TARGET_FPS = 60;
double frame_rate = 0, update_time = 0, render_time = 0;

unsigned long current_time() {
    return std::chrono::system_clock::now().time_since_epoch().count() / 10000l;
}

int main() {
    GLFWwindow *window;

    // Initialize the GLFW library
    if (!glfwInit())
        return -1;

    // Specify window attributes
    glfwWindowHint(GLFW_RESIZABLE, false);

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Center the window on the screen
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);
    glfwSetWindowMonitor(window, nullptr, (screen_width / 2) - (WINDOW_WIDTH / 2),
                         (screen_height / 2) - (WINDOW_HEIGHT / 2), WINDOW_WIDTH, WINDOW_HEIGHT, GLFW_DONT_CARE);

    // Make the window's context current
    glfwMakeContextCurrent(window);

    double targetDeltaFrames = 1000.0 / TARGET_FPS, targetDeltaCounter = 1000.0;
    double deltaFrames = 0, deltaCounter = 0;
    unsigned int frame_count = 0;
    unsigned long now = current_time(), last;

    unsigned long timer_start;
    unsigned long update_time_sum = 0, render_time_sum = 0;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        last = now;
        now = current_time();
        unsigned long passed = now - last;

        // Check if enough time has passed for a new frame
        deltaFrames += passed;
        if (deltaFrames >= targetDeltaFrames) {
            timer_start = current_time();

            // TODO update here

            update_time_sum += current_time() - timer_start;
            timer_start = current_time();

            // Clear the buffers
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Scale the window to have a correct ratio
            glPushMatrix();
            glScaled(1, (double) WINDOW_WIDTH / WINDOW_HEIGHT, 1);

            // TODO render here

            glPopMatrix();

            // Swap front and back buffers
            glfwSwapBuffers(window);

            render_time_sum += current_time() - timer_start;

            // Increase frame count
            frame_count++;

            deltaFrames -= targetDeltaFrames;
        }

        // Check if enough time has passed to report the fps
        deltaCounter += passed;
        if (deltaCounter >= targetDeltaCounter) {
            // Calculate stats
            frame_rate = frame_count;
            update_time = (double) update_time_sum / frame_count;
            render_time = (double) render_time_sum / frame_count;
            frame_count = 0;
            update_time_sum = 0;
            render_time_sum = 0;

            // Print FPS and update/render times
            std::cout << "fps: " << frame_rate << " / " << TARGET_FPS
                      << ", update time: " << std::setprecision(1) << update_time
                      << " ms, render time: " << std::setprecision(1) << render_time << " ms"
                      << std::fixed << std::endl;

            deltaCounter -= targetDeltaCounter;
        }

        // Poll for and process events
        glfwPollEvents();

        // Sleep until next frame
        if (deltaFrames < targetDeltaFrames - 10) {
            try {
                std::this_thread::sleep_for(std::chrono::milliseconds((long) (targetDeltaFrames - deltaFrames - 10)));
            } catch (...) {
                std::cerr << "Error occurred whilst trying to sleep!" << std::endl;
            }
        }
    }

    glfwTerminate();
    return 0;
}
