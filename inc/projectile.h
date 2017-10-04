#pragma once

#include <SFML/Graphics.hpp>

#include "unit.h"

#define SPEED 5.0f

class Projectile{
	public:
		Projectile(sf::RenderWindow* p_window,
				Faction p_faction);
		~Projectile();

		virtual void update();
		void draw();
		sf::VertexArray getBody();

	protected:
		sf::RenderWindow* _window;
		Faction _faction;
		sf::VertexArray _body;
};
