cmake_minimum_required(VERSION 3.22)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(Pong ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/dependencies/glfw/include/)
target_link_libraries(Pong ${CMAKE_SOURCE_DIR}/dependencies/glfw/lib-vc2019/glfw3.lib)
find_package(OpenGL REQUIRED)
target_link_libraries(Pong OpenGL::GL)
