cmake_minimum_required(VERSION 3.16)
project(ImGuiTest)
set(CMAKE_CXX_STANDARD 17)
find_package(glfw3 REQUIRED)
find_library(OpenGL_LIBRARY OpenGL)
add_executable(ImGuiTest src/main.cpp src/menu.cpp imgui/imgui.cpp imgui/imgui_tables.cpp imgui/imgui_draw.cpp imgui/imgui_widgets.cpp imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp)

target_include_directories(ImGuiTest PRIVATE
imgui
)

target_link_libraries(ImGuiTest PRIVATE
glfw ${OpenGL_LIBRARY})