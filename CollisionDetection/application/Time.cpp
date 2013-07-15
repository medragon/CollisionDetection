#include "Time.h"

sf::Clock Time::_clock;
float Time::_currentTime;
float Time::_deltaTime;

void Time::update()
{
	float newTime = _clock.getElapsedTime().asSeconds();
	_deltaTime = newTime - _currentTime;
	_currentTime = newTime;
}

float Time::now()
{
	return _currentTime;
}

float Time::deltaTime()
{
	return _deltaTime;
}