#include "infantry.h"

Infantry::Infantry(sf::RenderWindow* p_window, Map* p_map, Faction p_fac) :
       	Unit(p_window)
{
	_map = p_map;
	_faction = p_fac;

	_hp = Bar(_window, 5, 5);
	_hp.setPosition(sf::Vector2f(0, -10));
	_State = ALIVE;
	_position = sf::Vector2f(0, 0);

	int radius = 4;
	_body = sf::CircleShape(radius);
	_body.setOrigin(radius, radius);
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

State Infantry::update()
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

	if(_hp.getAmount() <= 0)
		_State = DEAD;

	return _State;
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

void Infantry::takeDamage(int p_damage)
{
	_hp.setAmount(_hp.getAmount() -  p_damage);
}
