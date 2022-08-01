#pragma once

#include "Engine/Core/Core.h"

#include "Engine/Scene/ECS/ECS.h"
//#include "Engine/Scene/Object.h"

namespace Copper {

	class Camera;
	class Object;

	class Scene {

		friend class Object;

	public:
		Object CreateObject(std::string name = "Object");
		void DestroyObject(Object obj);

		void Update();

	public:
		ECS::Registry registry;

		Camera* sceneCam;

	 };

}