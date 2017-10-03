#pragma once

#include <SFML/Graphics.hpp>

#include "testscene.h"

class App{
	public:
		App();// add error handling later
		~App();

		int run();

	private:
		sf::RenderWindow* _window;
		Scene* _current_scene;
};
