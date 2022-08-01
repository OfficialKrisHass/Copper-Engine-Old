#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Renderer/FrameBuffer.h"

#include "Engine/Scene/Object.h"
#include "Engine/Scene/Scene.h"

#include "Editor/Panels/SceneHierarchy.h"
#include "Editor/Panels/Properties.h"

using namespace Copper;

namespace Editor {

	class Editor {

	public:
		void Initialize();

		void Update();
		void UIUpdate();

		void Shutdown();

	private:
		SceneHierarchy sceneHierarchy;
		Properties properties;
		UVector2 viewportSize;

		Copper::Shared<Copper::FrameBuffer> fbo;

		//Scene
		Scene scene;

		Object square;
		Object camera;

		void RenderDockspace();

	};

}