#pragma once

#include "scene.h"
#include "infantry.h"

#include <list>

class TestScene : public Scene{
	public:
		TestScene(sf::RenderWindow* window);
		bool update(int p_ticks);

	private:
		std::list<Unit*> _units;
};
