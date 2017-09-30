#pragma once

#include <SFML/Graphics.hpp>

class Scene{
	public:
		Scene(sf::RenderWindow* p_window);
		virtual bool update(int p_ticks = 1) = 0;

	private:
		sf::RenderWindow* _window;
};
