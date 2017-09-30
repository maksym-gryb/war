#include "unit.h"

int Unit::_global_id = 0;

Unit::Unit(sf::RenderWindow* p_window)
{
	_id = _global_id++; 
	_window = p_window;
	_faction = 0;
}

int Unit::getHp()
{
	return _hp;
}

state Unit::getState()
{
	return _state;
}

int Unit::getId()
{
	return _id;
}

void Unit::setFaction(int p_faction)
{
	_faction = p_faction;
}

int Unit::getFaction()
{
	return _faction;
}

void Unit::setPosition(int p_x, int p_y)
{
	_position.x = p_x;
	_position.y = p_y;
}

void Unit::moveBy(int p_x, int p_y)
{
	_position.x += p_x;
	_position.y += p_y;
}

sf::Vector2f Unit::getPosition()
{
	return _position;
}
