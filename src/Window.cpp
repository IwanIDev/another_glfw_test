#include "Window.hpp"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

Window::Window()
{

}

Window::Window(std::string title, int width, int height)
{
	this->title = title;
	this->width = width;
	this->height = height;
}

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

int Window::init()
{
	int initCode = glfwInit();
	if(initCode == GLFW_FALSE) {
		fprintf(stderr, "ERR: GLFW failed to init.\n");
		return 1;
	}

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	this->glwindow = glfwCreateWindow(
		this->width,
		this->height,
		this->title.c_str(),
		NULL,
		NULL
	);

	glfwMakeContextCurrent(this->glwindow);
	glfwSetErrorCallback(error_callback);

	if(!this->glwindow) {
		fprintf(stderr, "ERR: GLFW window failed to create.\n");
		return 1;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	ImGui_ImplGlfw_InitForOpenGL(this->glwindow, true);
	ImGui_ImplOpenGL3_Init();

	return 0;
}


void Window::run()
{
	while(!glfwWindowShouldClose(this->glwindow)) {
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow();
		
		ImGui::Render();

		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(this->glwindow);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(this->glwindow);
	glfwTerminate();
}