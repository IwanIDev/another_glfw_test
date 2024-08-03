#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class Window
{
    private:
        GLFWwindow* glwindow;
        std::string title = "GLFW test window.";
        int width = 600;
        int height = 600;

    public:
        Window();
        Window(std::string title, int width, int height);

        int init();
        void run();
};