#pragma once

#include <SFML/Graphics.hpp>

enum state{
	ALIVE = 0,
	DEAD
};

class Unit{
	public:
		Unit(sf::RenderWindow* window);
		virtual state update() = 0;
		virtual void draw() = 0;

		int getHp();
		state getState();
		int getId();


	protected:
		int _hp;
		state _state;

		sf::RenderWindow* _window;

	private:
		int _id;
		static int _global_id;
};
