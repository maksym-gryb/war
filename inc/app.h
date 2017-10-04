#pragma once

#include <SFML/Graphics.hpp>

#include "testscene.h"

const float INPUT_RATE = 1000/60;
const float SCREEN_MOVE_SPEED = 4;

class App{
	public:
		App();// add error handling later
		~App();

		int run();

	private:
		sf::RenderWindow* _window;
		Scene* _current_scene;

		sf::Clock _clock_input;
};
