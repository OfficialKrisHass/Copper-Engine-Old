#pragma once

#include "Engine/Core/Core.h"

#include "Editor/Panels/Panel.h"

#include "Engine/Scene/Scene.h"
#include "Engine/Scene/Object.h"

namespace Editor {

	class SceneHierarchy : public Panel {

	public:
		SceneHierarchy() : Panel("Scene Hierarchy"), scene(nullptr) {}

		virtual void Render() override;

		inline void SetScene(Copper::Scene* scene) { this->scene = scene; }
		inline Copper::Object GetSelectedObject() { return selectedObject; }

	private:
		Copper::Scene* scene;
		Copper::Object selectedObject = { Copper::ECS::EntityID(-1, -1), nullptr};

	};

}