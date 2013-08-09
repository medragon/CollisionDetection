#include "Application.h"

#include "Time.h"

Application::Application(void) : _running(false)
{
}


Application::~Application(void)
{
}

void Application::build()
{
	_window = std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(1024, 768), "Collision Detection", sf::Style::Close));
	createResourceManagers();
	loadResources();

}

void Application::createResourceManagers()
{
	meshManager = std::shared_ptr<ResourceManager<Mesh>>(new ResourceManager<Mesh>());
}

void Application::loadResources()
{
	// test adding a object like race car
	meshManager->add("resources/mesh/car.obj");
}

void Application::run()
{
	_running = true;
	while(_running){
		control();
		test();
		Time::update();
	}
}

void Application::control()
{
	if (_window->isOpen()) {
		sf::Event event;
		while (_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) close();
	}
}

void Application::close()
{
	_window->close();
	_running = false;
}

void Application::test()
{
	sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Green);

	_window->clear();
    _window->draw(shape);
    _window->display();
}
