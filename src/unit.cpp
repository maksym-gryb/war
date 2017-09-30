#include "unit.h"

int Unit::_global_id = 0;

Unit::Unit(sf::RenderWindow* p_window)
{
	_id = _global_id++; 
	_window = p_window;
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
