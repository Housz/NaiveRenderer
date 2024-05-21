cmake_minimum_required(VERSION 3.15)
project(NaiveRenderer)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_subdirectory(0)
add_subdirectory(1)