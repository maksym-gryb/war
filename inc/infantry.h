#pragma once

#include "unit.h"

class Infantry : public Unit{
	public:
		Infantry(sf::RenderWindow* p_window);
		~Infantry();

		state update();
		void draw();

		void setPosition(int p_x, int p_y);
		void moveBy(int p_x, int p_y);

	private:
		sf::CircleShape _body;
};
