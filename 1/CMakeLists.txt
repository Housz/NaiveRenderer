cmake_minimum_required(VERSION 3.15)

add_executable(renderer1)
file(GLOB sources CMAKE_CONFIGURE_DEPENDS *.cpp *.h)
target_sources(renderer1 PUBLIC ${sources})

target_link_libraries(renderer1 PUBLIC glfw)
target_link_libraries(renderer1 PUBLIC glad::glad)
target_link_libraries(renderer1 PUBLIC glm::glm)