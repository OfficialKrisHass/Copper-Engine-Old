//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Source file of the Windows implementation of the Window System.

#include "cupch.h"

#include <GLAD/glad.h>
#include "WindowsWindow.h"

#include "Copper/Core/Core.h"

#include "Copper/Events/Event.h"
#include "Copper/Events/ApplicationEvent.h"
#include "Copper/Events/KeyEvent.h"
#include "Copper/Events/MouseEvent.h"

namespace Copper {

	static bool glfwInitialized;

	//The Implementation of the Function we use to Create the Window
	//TODO: Remove this function and create the specific Window Implementation
	//Automatically based on the Platform
	Window* Window::Create(const WindowProps& props) {

		return new WindowsWindow(props);

	}

	//Constructor for the Windows Implementation, here we Initialize 
	//and setup the Window and Window Events.
	WindowsWindow::WindowsWindow(const WindowProps& props) {

		//Set the WindowData variables to what was given to us when
		//we Made the engine
		data.title = props.title;
		data.width = props.width;
		data.height = props.height;

		EngineLog("Creating Window {0} (width: {1}, height: {2}", data.title, data.width, data.height);

		//Initialize the GLFW Library and check if the Initialization was successfull
		if (!glfwInitialized) {

			//Initialize GLFW and if not succesfull Log it
			int success = glfwInit();
			if (!success) { EngineLogError("Could not Initialize GLFW! File: WindowsWindow.cpp"); }

			//Set the GLFW Error Callback
			glfwSetErrorCallback([](int error, const char* description) { EngineLogError("GLFW Error ({0}): {1}", error, description); });

			glfwInitialized = true;

		}

		//Set Window Hints for our Rendering Library
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		//Create The GLFW Window Handle and set the context for GLAD
		window = glfwCreateWindow((int)data.width, (int)data.height, data.title, NULL, NULL);
		glfwMakeContextCurrent(window);

		//Initialize Glad and store if it was succesfull and if not Display an error
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if(!status) { EngineLogError("Failed to Initialize GLAD! File: WindowsWndow.cpp"); }

		//Here we set the User Pointer to point to where we store our WindowData
		//Later when we are handling window events, we can simply get the WindowData
		//struct if we have the GLFW Window Handle. this is Useful mainly for events
		glfwSetWindowUserPointer(window, &data);
		SetVSync(true);

		//------------------------------------
		//-----Set the GLFW Window Events-----
		//------------------------------------

		//WindowResize Event
		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {

			//Get back the WindowData struct we've set up earlier
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			//Set the new Width and Height
			data.width = width;
			data.height = height;

			//Create a WindowResizeEvent and give it the new size and then call the
			//Event Callback we specifies previously (current Application::OnEvent)
			WindowResizeEvent e(width, height);
			data.eventCallback(e);

		});

		//WindowClose Event
		glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {

			//Get back the WindowData struct we've set up earlier
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			//Create a WindowResizeEvent and call the Event Callback we specified
			//previously (current Application::OnEvent in Application.cpp)
			WindowCloseEvent e;
			data.eventCallback(e);

		});

		//Keyboard Event, since GLFW has only one callback for this we need to figure out
		//What event happened exactly, thankfully github gives us a lot of information for this
		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			//Get back the WindowData struct we've set up earlier
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			//Figure out what we did and then Create the right event and send it to the Event Callback
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

		glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int keycode) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			KeyTypedEvent event(keycode);
			data.eventCallback(event);

		});

		//Mouse Event, very similar to Key Event just a bit easier since we can only do 2 things
		//with a mouse,
		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int scancode) {

			//Get back the WindowData struct we've set up earlier
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			//Figure out what we did and then Create the right event and send it to the Event Callback
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

		//Scroll Event
		glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset) {

			//Get back the WindowData struct we've set up earlier
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			//Create a MouseScrolledEvent, set neededparameters and call the Event
			//Callback we specified previously (current Application::OnEvent
			//in Application.cpp)
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.eventCallback(event);

		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos) {

			//Get back the WindowData struct we've set up earlier
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			//Create a MouseMovedEvent, set needed parameters and call the Event
			//Callback we specified previously (current Application::OnEvent
			//in Application.cpp)
			MouseMovedEvent event((float)xPos, (float)yPos);
			data.eventCallback(event);

		});

	}

	//Destructor that terminates the GLFW library and destroys the Window
	WindowsWindow::~WindowsWindow() {

		EngineLog("Closing Window {0}", data.title);

		glfwDestroyWindow(window);
		glfwTerminate();

	}

	//Function that tells our window if we are using VSync
	void WindowsWindow::SetVSync(bool enabled) {

		if (enabled) {

			glfwSwapInterval(1);

		}
		else {

			glfwSwapInterval(0);

		}

	}

	//Update function that updates the Window
	void WindowsWindow::OnUpdate() {

		//Polls the Window Events and Swaps the Buffers.
		glfwPollEvents();
		glfwSwapBuffers(window);

	}

}