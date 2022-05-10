//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

#include "cupch.h"
#include "LayerStack.h"

namespace Copper {

	LayerStack::~LayerStack() {

		for (Layer* layer : layers) {

			delete layer;

		}

	}

	void LayerStack::PushLayer(Layer* layer) {

		layers.emplace(layers.begin() + insertIndex, layer);
		insertIndex++;

		layer->OnAttach();

	}

	void LayerStack::PushOverlay(Layer* overlay) {

		layers.emplace_back(overlay);

		overlay->OnAttach();

	}

	void LayerStack::PopLayer(Layer* layer) {

		auto it = std::find(layers.begin(), layers.end(), layer);

		if (it != layers.end()) {

			layers.erase(it);
			insertIndex--;

			layer->OnDetach();

		}

	}

	void LayerStack::PopOverlay(Layer* overlay) {

		auto it = std::find(layers.begin(), layers.end(), overlay);

		if (it != layers.end()) {

			layers.erase(it);
			
			overlay->OnDetach();

		}

	}

}