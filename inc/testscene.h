#pragma once

#include "scene.h"

#include "infantry.h"
#include "map.h"

#include <list>

#define UPDATE_INTERVAL 60

class TestScene : public Scene{
	public:
		TestScene(sf::RenderWindow* window);
		bool update(int p_ticks);

	private:
		Map _map;
		sf::Clock _clock;
};
