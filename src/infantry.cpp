#include "infantry.h"

Infantry::Infantry(sf::RenderWindow* p_window, Map* p_map, Faction p_fac) :
       	Unit(p_window)
{
	_map = p_map;
	_faction = p_fac;

	_hp = 5;
	_state = ALIVE;
	_position = sf::Vector2f(0, 0);

	_body = sf::CircleShape(4);
	_body.setOrigin(4, 4);
	switch(_faction)
	{
		case RED:
			_body.setFillColor(sf::Color::Red);
			break;
			
		case BLUE:
			_body.setFillColor(sf::Color::Blue);
			break;

		default:
			// register non-critical error
			break;
	}

	_reload_rate_clock.restart();
}

Infantry::~Infantry()
{}

state Infantry::update()
{
	if(_faction == RED)
		moveBy(0.3, 0.3);
	else if(_faction == BLUE)
		moveBy(0.0, -0.5);

	auto it = _map->unitBegin();
	while(it != _map->unitEnd())
	{
		if(this->getFaction() != (*it)->getFaction()
		&& this->inRangeWith(*it)
		&& _reload_rate_clock.getElapsedTime().asMilliseconds()
			> 1000/RELOAD_RATE)
		{
				this->shoot(*it);
				_reload_rate_clock.restart();
		}

		it++;
	}

	if(_hp <= 0)
		_state = DEAD;

	return _state;
}

bool Infantry::inRangeWith(Unit* p_target)
{
	float dx = this->getPosition().x - p_target->getPosition().x;
	float dy = this->getPosition().y - p_target->getPosition().y;

	float d = sqrt(dx*dx + dy*dy);

	if(d <= SIGHT_DISTANCE)
		return true;
	
	return false;
}

void Infantry::shoot(Unit* p_target)
{
	_map->addProjectile(new Bullet(_window,
				       _map,
				       _faction,
				       this->getPosition(),
				       p_target->getPosition()));

	_reload_rate_clock.restart();
}
