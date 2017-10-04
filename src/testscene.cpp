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
		bool collision = false;
		(*projectile_it)->update();
		(*projectile_it)->draw();

		// Handler Collision
		auto unit_it = _map.unitBegin();
		while(unit_it != _map.unitEnd())
		{
			if(collides((*unit_it)->getBody(), (*projectile_it)->getBody()))
			{
				projectile_it = _map.eraseProjectile(projectile_it);
				collision = true;

				if((*unit_it)->loseHp(1) == DEAD)
					_map.eraseUnit(unit_it);
				break;
			}

			unit_it++;
		}
		if(!collision)
			projectile_it++;
	}

	_window->display();

	return true;
}

bool TestScene::collides(sf::CircleShape p_circle, sf::VertexArray p_lines)
{
	for(int i = 0; i < p_lines.getVertexCount(); i++)
	{
		float x = p_circle.getPosition().x - p_lines[i].position.x;
		float y = p_circle.getPosition().y - p_lines[i].position.y;
		float distance = sqrt(x*x + y*y);

		if(distance <= p_circle.getRadius())
			return true;
	}

	return false;
}
