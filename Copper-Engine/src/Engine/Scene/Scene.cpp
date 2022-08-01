#include "cupch.h"
#include "Scene.h"

#include "Engine/Renderer/Renderer.h"

#include "Engine/Scene/Object.h"

#include "Engine/Scene/Components/Transform.h"
#include "Engine/Scene/Components/Tag.h"

#include "Engine/Scene/Components/Camera.h"
#include "Engine/Scene/Components/Mesh.h"

namespace Copper {

	int ECS::cCounter = 0;

	Object Scene::CreateObject(std::string name) {

		Object obj(registry.CreateEntity(), this);

		obj.transform = registry.AddComponent<Transform>(obj.id);
		Tag& tag = *registry.AddComponent<Tag>(obj.id);
		tag.name = name;

		return obj;

	}

	void Scene::DestroyObject(Object obj) {

		registry.DestroyEntitiy(obj.id);

	}

	void Scene::Update() {

		Copper::Renderer::ClearColor(0.18f, 0.18f, 0.18f);

		for (uint64_t ent : ECS::SceneView<Camera>(registry)) {

			Camera* cam = registry.GetComponent<Camera>(ent);
			sceneCam = cam;

		}

		for (uint64_t ent : ECS::SceneView<Mesh>(registry)) {

			Mesh* mesh = registry.GetComponent<Mesh>(ent);

			Renderer::Render(mesh, sceneCam);

		}

	}

}