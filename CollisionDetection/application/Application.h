#pragma once

#include <memory>
#include <SFML\Graphics.hpp>

#include "../resourcemanagement/ResourceManager.h"
#include "../game/Mesh.h"


class Application
{
	private:
		std::shared_ptr<sf::RenderWindow> _window;
		bool _running;

		std::shared_ptr<ResourceManager<Mesh>> meshManager;

		void control();
		void close();

		void createResourceManagers();
		void loadResources();

		// method for testing sfml by drawing a circle
		void test();

	public:
		Application(void);
		~Application(void);

		void build();
		void run();

};

