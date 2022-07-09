cmake_minimum_required(VERSION 3.22)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pong src/main.cpp src/player.cpp src/ball.cpp src/PongGameHandler.cpp)

include_directories(${CMAKE_SOURCE_DIR}/dependencies/glfw/include/)
target_link_libraries(Pong ${CMAKE_SOURCE_DIR}/dependencies/glfw/lib-vc2019/glfw3.lib)
find_package(OpenGL REQUIRED)
target_link_libraries(Pong OpenGL::GL)
