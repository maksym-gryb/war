#include "testscene.h"

TestScene::TestScene(sf::RenderWindow* p_window) : Scene(p_window)
{
	Unit* u = new Infantry(_window, &_map, RED);
	u->setPosition(10, 10);
	_map.addUnit(u);
	
	u = new Infantry(_window, &_map, BLUE);
	u->setPosition(100, 100);
	_map.addUnit(u);

	_clock.restart();
}

bool TestScene::update(int p_ticks)
{
	if(_clock.getElapsedTime().asMilliseconds() < 1000/UPDATE_INTERVAL)
		return true;

	_clock.restart();

	_window->clear();

	auto unit_it = _map.unitBegin();

	while(unit_it != _map.unitEnd())
	{
		(*unit_it)->update();
		(*unit_it)->draw();
		unit_it++;
	}

	auto projectile_it = _map.projectileBegin();

	while(projectile_it != _map.projectileEnd())
	{
		(*projectile_it)->update();
		(*projectile_it)->draw();
		projectile_it++;
	}

	_window->display();

	return true;
}
