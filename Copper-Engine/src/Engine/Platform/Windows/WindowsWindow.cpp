#include "cupch.h"
#include "WindowsWindow.h"

#include "Engine/Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace Copper {

	WindowsWindow::WindowsWindow(WindowProps props) {

		this->data.width  = props.width;
		this->data.height = props.height;
		this->data.title  = props.title;

		Log("Creating {0} Window (width: {1}, height: {2})", data.title, data.width, data.height);

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(data.width, data.height, data.title.c_str(), NULL, NULL);
		if (!window) { LogError("Couldn't create Window(Title: {0}, Width: {1}, Height: {2}", data.title, data.width, data.height); return; }

		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) { LogError("Failed to initialize GLAD!"); return; }

		glfwSetWindowUserPointer(window, &data);

		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {

			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			data.width = width;
			data.height = height;

			WindowResizeEvent e(width, height);
			data.eventCallback(e);

		});
		glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {

			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			WindowCloseEvent e;
			data.eventCallback(e);

		});
		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			switch (action) {

			case GLFW_PRESS: {

				KeyPressedEvent event(key, 0);
				data.eventCallback(event);

				break;

			}

			case GLFW_RELEASE: {

				KeyReleasedEvent event(key);
				data.eventCallback(event);

				break;
			}

			case GLFW_REPEAT: {

				KeyPressedEvent event(key, 1);
				data.eventCallback(event);

				break;

			}

			}

		});
		/*glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int keycode) {

			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			KeyTypedEvent event(keycode);
			data.eventCallback(event);

		});*/
		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int scancode) {

			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			switch (action) {

			case GLFW_PRESS: {

				MouseButtonPressedEvent event(button);
				data.eventCallback(event);

				break;
			}

			case GLFW_RELEASE: {

				MouseButtonReleasedEvent event(button);
				data.eventCallback(event);

				break;

			}

			}

		});
		glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset) {

			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float) xOffset, (float) yOffset);
			data.eventCallback(event);

		});
		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos) {

			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float) xPos, (float) yPos);
			data.eventCallback(event);

		});

	}

	void WindowsWindow::Update() {

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	void WindowsWindow::Shutdown() {

		Log("Closing Window {0}", data.title);

		glfwDestroyWindow(window);
		glfwTerminate();

	}

}