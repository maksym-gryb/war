#include "infantry.h"

Infantry::Infantry(sf::RenderWindow* p_window) : Unit(p_window)
{
	_hp = 5;
	_state = ALIVE;
	_position = sf::Vector2f(0, 0);

	_body = sf::CircleShape(4);
	_body.setFillColor(sf::Color::White);
}

Infantry::~Infantry()
{}

state Infantry::update()
{
	moveBy(1, 1);

	draw();

	return _state;
}

void Infantry::draw()
{
	_window->draw(_body);
}

void Infantry::setPosition(int p_x, int p_y)
{
	_body.setPosition(sf::Vector2f(p_x, p_y));

	Unit::setPosition(p_x, p_y);
}

void Infantry::moveBy(int p_x, int p_y)
{
	_body.move(p_x, p_y);

	Unit::moveBy(p_x, p_y);
}
