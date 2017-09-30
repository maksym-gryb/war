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

		void setFaction(int p_faction);
		int getFaction();

		void setPosition(int p_x, int p_y);
		void moveBy(int p_x, int p_y);

		sf::Vector2f getPosition();

	protected:
		int _hp;
		state _state;
		int _faction;

		sf::Vector2f _position;

		sf::RenderWindow* _window;

	private:
		int _id;
		static int _global_id;
};
