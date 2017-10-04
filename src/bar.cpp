#include "bar.h"

Bar::Bar()
{}

Bar::Bar(sf::RenderWindow* p_window, int p_max, int p_amount)
{
	float height = 3.0f;
	float width  = 20.0f;
	float thickness = 1.0f;
	_window = p_window;

	_max = p_max;
	_amount = p_amount;

	sf::Vector2f position = sf::Vector2f(width, height);
	sf::Vector2f origin = position / 2.0f;

	_background = sf::RectangleShape(position);
	_background.setFillColor(sf::Color(100, 100, 100));
	_background.setOrigin(origin);

	_fill = sf::RectangleShape(position);
	_fill.setFillColor(sf::Color::Red);
	_fill.setOrigin(origin);

	position + sf::Vector2f(2.0f, 2.0f);
	_outline = sf::RectangleShape(position);
	_outline.setFillColor(sf::Color::Transparent);
	_outline.setOutlineColor(sf::Color::White);
	_outline.setOutlineThickness(1);
	_outline.setOrigin(position / 2.0f);
}

Bar::~Bar()
{}

void Bar::draw()
{
	_window->draw(_background);
	_window->draw(_fill);
	_window->draw(_outline);
}

void Bar::setMax(int p_num)
{
	_max = p_num;
}

int Bar::getMax()
{
	return _max;
}

void Bar::setAmount(int p_num)
{
	_amount = p_num;

	float ratio = float(_amount) / float(_max);
	float width = _background.getSize().x * ratio;
	float height = _background.getSize().y;

	_fill.setSize(sf::Vector2f(width, height));
}

int Bar::getAmount()
{
	return _amount;
}

void Bar::setPosition(sf::Vector2f p_pos)
{
	_background.setPosition(p_pos);	
	_fill.setPosition(p_pos);	
	_outline.setPosition(p_pos);	
}

void Bar::move(sf::Vector2f p_vector)
{
	_background.move(p_vector);	
	_fill.move(p_vector);	
	_outline.move(p_vector);	
}

sf::Vector2f Bar::getPosition()
{
	return _background.getPosition();
}
