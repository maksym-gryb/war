#pragma once

#include <SFML/Graphics.hpp>

#include "bar.h"

#include <cmath>

enum State{
	ALIVE = 0,
	DEAD
};

enum Faction{
	NONE = 0,
	RED,
	BLUE
};

class Unit{
	public:
		Unit(sf::RenderWindow* window);
		virtual State update() = 0;
		void draw();

		int getHp();
		State loseHp(int p_hp);
		State getState();
		int getId();

		void setFaction(Faction p_faction);
		Faction getFaction();

		void setPosition(float p_x, float p_y);
		void moveBy(float p_x, float p_y);

		sf::Vector2f getPosition();

		bool operator==(const Unit* that);
		bool operator!=(const Unit* that);

		sf::CircleShape getBody();

	protected:
		Bar _hp;
		State _State;
		Faction _faction;

		sf::Vector2f _position;

		sf::CircleShape _body;

		sf::RenderWindow* _window;

	private:
		int _id;
		static int _global_id;
};
