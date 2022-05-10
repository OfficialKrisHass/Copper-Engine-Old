//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the Source file for the OpenGL Renderer Implementation

#include "cupch.h"
#include "OpenGLRenderer.h"

//It's important that we include this inside the .cpp file because only the OpenGL
//Implementations should have access to the Renderer API. This is so that the Engine
//Client can't just render random stuff
#include <GLAD/glad.h>

namespace Copper {

	//Function that Initializes the Renderer
	void OpenGLRenderer::Initialize() {

		//Enables the OpenGL Blending funcinality
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//Enables the Depth Buffer so that it won't render something that is not visible
		glEnable(GL_DEPTH_TEST);

		//Enables Culling so that only one face will be visible, and that face is indicated
		//by the way how the vertices are connected, in our case the face that is connected
		//in Counter Clock Wise way wil be renderer
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);

		//Sets the Polygon Mode into Fill. In other words, it makes it so that it renders
		//the whole thing. If we would want to change it so that it would render the
		//wireframe, we would need to change GL_FILL into GL_LINE
		glPointSize(10.0f);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}

	void OpenGLRenderer::ClearColor(float r, float g, float b) {

		//Clears the Background to a color we specified and clears the
		//Color and Depth Buffer bits
		glClearColor(r, g, b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	}

	//Function that sets the Rendering Viewport. The Rendering Viewport is basically
	//Where the Renderer Should Render the things. The Viewport can change when the Window
	//Is resized so this function should be called with the OnWindowResizeEvent.
	void OpenGLRenderer::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {

		//Updates the Viewport
		glViewport(x, y, width, height);

	}

	//The Main Render Function that Renders the object with the Camera. For now it only
	//Renders one object but Later should be changed to just take a scene and render the
	//Whole Scene with Lightning and other things
	void OpenGLRenderer::Render(const Shared<Mesh>& mesh, const Shared<Camera>& cam) {

		//Binds our VertexArray and Shader
		mesh->BindVAO();
		shader->Bind();

		//Move the Camera
		//cam->Move();

		//Sets our Model View and Projection Matrices
		shader->SetMat4(mesh->transform->CreateModelMatrix(), "Model");
		shader->SetMat4(cam->CreateViewMatrix(), "View");
		shader->SetMat4(cam->CreateProjectionMatrix(), "Projection");

		//Draw the Object
		glDrawElements(GL_TRIANGLES, mesh->GetVertexCount(), GL_UNSIGNED_INT, 0);

	}

}