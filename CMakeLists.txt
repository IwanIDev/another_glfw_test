cmake_minimum_required(VERSION 3.20)

project(glfw-example)

find_package(PkgConfig REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${MY_SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME}
PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

target_link_libraries(${CMAKE_PROJECT_NAME}
PUBLIC
GLEW::GLEW
glfw
imgui::imgui
)