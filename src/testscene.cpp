#include "testscene.h"

TestScene::TestScene(sf::RenderWindow* p_window) : Scene(p_window)
{
	Unit* u = new Infantry(p_window);
	u->setPosition(10, 10);
	_units.push_front(u);
}

bool TestScene::update(int p_ticks)
{
	for(Unit* u : _units)
		u->update();
}
