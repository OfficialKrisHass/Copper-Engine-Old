#include "cupch.h"
#include "SceneHierarchy.h"

#include "Engine/Scene/Components/Tag.h"

#include <ImGui/imgui.h>

namespace Editor {

	using namespace Copper;

	void SceneHierarchy::Render() {

		ImGui::Begin(name.c_str());

		if (!scene) return;

		for (uint64_t ent : ECS::SceneView<>(scene->registry)) {

			Object obj{ ent, scene };
			std::string& name = obj.GetComponent<Tag>()->name;
			ImGuiTreeNodeFlags flags = ((selectedObject == obj) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnArrow;

			bool opened = ImGui::TreeNodeEx((void*)(uint64_t)(uint32_t) obj, flags, name.c_str());

			if (ImGui::IsItemClicked()) { selectedObject = obj; }

		}

		ImGui::End();

		//Log(selectedObject.transform->position.x);

	}

}