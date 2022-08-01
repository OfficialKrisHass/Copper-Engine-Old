#include "cupch.h"
#include "Properties.h"

#include "Engine/Scene/Components/Tag.h"

#include <ImGui/imgui.h>
#include <ImGui/imgui_internal.h>

#include <cstring>

#ifdef _MSVC_LANG
#define _CRT_SECURE_NO_WARNINGS
#endif

namespace Editor {

	using namespace Copper;

	template<typename T>
	static void DrawComponent(const std::string& name) {

		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_AllowItemOverlap | ImGuiTreeNodeFlags_FramePadding;

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2{ 4, 4 });
		ImGui::VerticalSeparator();

		ImGui::TreeNodeEx((void*)typeid(T).hash_code(), flags, name.c_str());

		ImGui::PopStyleVar();
		ImGui::TreePop();

	}

	void Properties::Render() {

		ImGui::Begin(name.c_str());

		if (!selectedObject) { ImGui::End(); return; }

		char buffer[128];
		memset(buffer, 0, sizeof(buffer));
		std::strncpy(buffer, selectedObject.GetComponent<Tag>()->name.c_str(), sizeof(buffer));

		if (ImGui::InputText("##Name", buffer, sizeof(buffer))) {

			selectedObject.GetComponent<Tag>()->name = std::string(buffer);

		}

		DrawComponent<Transform>("Transform");

		ShowVector3("Position:", selectedObject.GetComponent<Transform>()->position);
		ShowVector3("Rotation:", selectedObject.GetComponent<Transform>()->rotation);
		ShowVector3("Scale:", selectedObject.GetComponent<Transform>()->scale);

		ImGui::End();

	}

	void Properties::ShowVector3(std::string name, Vector3& position) {

		//Begin
		ImGui::PushID(name.c_str());

		//Text
		ImGui::Columns(2);
		ImGui::SetColumnWidth(0, 100.0f);
		ImGui::Text(name.c_str());
		ImGui::NextColumn();

		//Settings
		ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });

		//Vars
		float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
		ImVec2 buttonSize = { lineHeight + 3.0f, lineHeight };

		//X
		ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.1f, 0.1f, 1.0f });
		ImGui::Button("X", buttonSize);
		ImGui::PopItemFlag();
		ImGui::PopStyleColor();

		ImGui::SameLine();
		ImGui::DragFloat("##X", &position.x, 0.01f, 0.0f, 0.0f, "%.2f");
		ImGui::PopItemWidth();
		ImGui::SameLine();

		//Y
		ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.1f, 0.1f, 1.0f });
		ImGui::Button("Y", buttonSize);
		ImGui::PopItemFlag();
		ImGui::PopStyleColor();

		ImGui::SameLine();
		ImGui::DragFloat("##Y", &position.y, 0.01f, 0.0f, 0.0f, "%.2f");
		ImGui::PopItemWidth();
		ImGui::SameLine();

		//Z
		ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.1f, 0.1f, 1.0f });
		ImGui::Button("Z", buttonSize);
		ImGui::PopItemFlag();
		ImGui::PopStyleColor();

		ImGui::SameLine();
		ImGui::DragFloat("##Z", &position.z, 0.01f, 0.0f, 0.0f, "%.2f");
		ImGui::PopItemWidth();

		//End
		ImGui::PopStyleVar();
		ImGui::Columns(1);
		ImGui::PopID();

	}

}