#pragma once

#include <SFML\System.hpp>

class Time
{
	private: 
		static sf::Clock _clock;
		static float _currentTime;
		static float _deltaTime;

		Time(void){};

	public:
		static void update();
		static float now();
		static float deltaTime();

};

