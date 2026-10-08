#include "imgui.h"
#include "GLFW/glfw3.h"
#include "../imgui/backends/imgui_impl_glfw.h"
#include "../imgui/backends/imgui_impl_opengl3.h"
#include <iostream>
using namespace std;

void RenderMenu();

int main()
{
    // Initialize
    ImGui::CreateContext();
    glfwInit();
    cout << "Dear ImGui Initialized" << endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "ImGuiTest", NULL, NULL);
    glfwMakeContextCurrent(window);

    ImGui_ImplGlfw_InitForOpenGL(window, true);

    // OpenGL error-out check
    if (!ImGui_ImplOpenGL3_Init("#version 150"))
    {
        cout << "OpenGL backend failed!" << endl;
        return 1;
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Create NewFrame
        ImGui_ImplGlfw_NewFrame();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        // Render ImGui
        RenderMenu();
        ImGui::Render();

        // Window Fix
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render Frame
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // End
    ImGui_ImplGlfw_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}