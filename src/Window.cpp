#include "Window.hpp"

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
    if(glfwInit() == GLFW_FALSE){
        fprintf(stderr, "ERR: GLFW failed to init.\n");
        return 1;
    }

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    glfwWindowHint(GLFW_VISIBLE, GL_TRUE);  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // A context can be created with any OpenGL 3.x version.  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2); // A context needs to be created with at least 3.2 OpenGL version.
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Use the core profile of OpenGL, which includes only the most modern and forward-compatible features of the specified OpenGL version.  
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Sets a hint for GLFW to enable forward compatibility for the OpenGL context

    this->glwindow = glfwCreateWindow(
        this->width,
        this->height,
        this->title.c_str(),
        NULL,
        NULL
    );
    glfwMakeContextCurrent(glwindow);
    glfwSetErrorCallback(error_callback);

    if (!glwindow)
    {
        fprintf(stderr, "ERR: GLFW window failed to create.\n");
        return 1;
    }

    // IMGUI init
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
    while (!glfwWindowShouldClose(this->glwindow)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow(); // Show demo window! :)

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(glwindow);
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(glwindow);
    glfwTerminate();
}