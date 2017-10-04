#pragma once

#include "unit.h"

#include "map.h"
#include "bullet.h"

#define SIGHT_DISTANCE 100.0f
#define RELOAD_RATE 2.0f

class Infantry : public Unit{
	public:
		Infantry(sf::RenderWindow* p_w, Map* p_map, Faction p_fac);
		~Infantry();

		State update();

		bool inRangeWith(Unit* p_target);
		void shoot(Unit* p_target);

		void takeDamage(int p_damage);

	private:
		Map* _map;
		sf::Clock _reload_rate_clock;
};
