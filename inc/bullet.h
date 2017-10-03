
#pragma once

#include "projectile.h"

#include "map.h"

#define SPEED 5.0f

class Bullet : public Projectile{
	public:
		static Bullet* create(sf::RenderWindow* p_window,
					Map* p_map,
					Unit* p_from,
					Unit* p_to);

	public:
		Bullet(sf::RenderWindow* p_window, Map* p_map,
				Faction p_faction, sf::Vector2f p_pos,
				sf::Vector2f p_target);
		~Bullet();

		void update();
		void draw();

		sf::Vector2f unitVector(sf::Vector2f source,
					sf::Vector2f target);

	private:
		Map* _map;

		sf::Vertex _line[2];

		sf::Vector2f _velocity;
};
