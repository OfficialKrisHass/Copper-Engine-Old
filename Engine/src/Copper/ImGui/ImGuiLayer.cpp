//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "ImGuiLayer.h"

#include "Copper/Core/Application.h"

#include "ImGui/imgui.h"

#define IMGUI_IMPL_API
#include "ImGui/examples/imgui_impl_opengl3.h"
#include "ImGui/examples/imgui_impl_glfw.h"

#include <GLFW/glfw3.h>

namespace Copper {

	void ImGuiLayer::OnAttach() {

		IMGUI_CHECKVERSION();

		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		ImGui::StyleColorsDark();

		ImGuiStyle& style = ImGui::GetStyle();

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {

			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;

		}

		Application& app = Application::Get();

		ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(Application::Get().GetGLFWWindow()), true);
		ImGui_ImplOpenGL3_Init("#version 330");

		EngineLog("Layer: {0} Succesfully Attached", name);

	}

	void ImGuiLayer::Begin() {

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

	}

	void ImGuiLayer::OnImGuiRender() {

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

	}

	void ImGuiLayer::End() {

		ImGuiIO& io = ImGui::GetIO();

		io.DisplaySize = ImVec2(Application::Get().GetWindow().GetWidth(), Application::Get().GetWindow().GetHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {

			GLFWwindow* backupCurrentContext = glfwGetCurrentContext();

			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();

			glfwMakeContextCurrent(backupCurrentContext);

		}

	}

	void ImGuiLayer::OnDetach() {

		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		EngineLog("Layer {0}: Detached", name);

	}

}