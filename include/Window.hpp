#pragma once
#include <GLFW/glfw3.h>
#include <string>

class Window
{
	private:
		GLFWwindow* glwindow;
		std::string title = "GLFW test window";
		int width = 800;
		int height = 600;
	
	public:
		Window();
		Window(std::string title, int width, int height);

		int init();
		void run();
};