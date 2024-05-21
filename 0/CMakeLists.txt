cmake_minimum_required(VERSION 3.15)

add_executable(renderer0)
file(GLOB sources CMAKE_CONFIGURE_DEPENDS *.cpp *.h)
target_sources(renderer0 PUBLIC ${sources})

target_link_libraries(renderer0 PUBLIC glfw)
target_link_libraries(renderer0 PUBLIC glad::glad)
target_link_libraries(renderer0 PUBLIC glm::glm)