#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Scene/Object.h"

#include "Editor/Panels/Panel.h"

namespace Editor {

	class Properties : public Panel {

	public:
		Properties() : Panel("Properties") {}

		virtual void Render() override;

		inline void SetSelectedObject(Copper::Object obj) { this->selectedObject = obj; }

	private:
		Copper::Object selectedObject;

		void ShowVector3(std::string name, Copper::Vector3& position);

	};

}