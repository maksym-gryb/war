#include "unit.h"

int Unit::_global_id = 0;

Unit::Unit(sf::RenderWindow* p_window)
{
	_id = _global_id++; 
	_window = p_window;
	_faction = NONE;
}

void Unit::draw()
{
	_window->draw(_body);
	_hp.draw();
}

int Unit::getHp()
{
	return _hp.getAmount();
}

State Unit::loseHp(int p_hp)
{
	_hp.setAmount(_hp.getAmount() - p_hp);

	if(_hp.getAmount() <= 0)
		return DEAD;
	return ALIVE;
}

State Unit::getState()
{
	return _State;
}

int Unit::getId()
{
	return _id;
}

void Unit::setFaction(Faction p_faction)
{
	_faction = p_faction;
}

Faction Unit::getFaction()
{
	return _faction;
}

void Unit::setPosition(float p_x, float p_y)
{
	sf::Vector2f diff = _hp.getPosition() - _body.getPosition();

	_position.x = p_x;
	_position.y = p_y;

	_body.setPosition(p_x, p_y);
	_hp.setPosition(_body.getPosition() + diff);
}

void Unit::moveBy(float p_x, float p_y)
{
	_position.x += p_x;
	_position.y += p_y;

	_body.move(sf::Vector2f(p_x, p_y));
	_hp.move(sf::Vector2f(p_x, p_y));
}

sf::Vector2f Unit::getPosition()
{
	return _body.getPosition();
	//return _position;
}

bool Unit::operator==(const Unit* that)
{
	return this->_id == that->_id;
}

bool Unit::operator!=(const Unit* that)
{
	return this->_id != that->_id;
}

sf::CircleShape Unit::getBody()
{
	return _body;
}
