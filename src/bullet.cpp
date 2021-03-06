#include "bullet.h"

Bullet* Bullet::create(sf::RenderWindow* p_window,
			Map* p_map,
			Unit* p_from,
			Unit* p_to)
{
	Bullet* b = new Bullet(p_window,
			       p_map,
			       p_from->getFaction(),
			       p_from->getPosition(),
			       p_to->getPosition());

	return b;
}

Bullet::Bullet(sf::RenderWindow* p_window,
		Map* p_map,
		Faction p_faction,
		sf::Vector2f p_pos,
		sf::Vector2f p_target)
	: Projectile(p_window, p_faction)
{
	_map = p_map;

	auto norm = unitVector(p_pos, p_target);

	_body = sf::VertexArray(sf::LineStrip, 2);
	_body[0].position = p_pos;
	_body[0].color  = sf::Color::White;
	_body[1].position = p_pos + norm*4.0f;
	_body[1].color = sf::Color::White;

	_velocity = norm * SPEED;
	
	_map->addProjectile(this);
}

Bullet::~Bullet()
{}

void Bullet::update()
{
	_body[0].position = _body[0].position + _velocity;
	_body[1].position = _body[1].position + _velocity;
}

sf::Vector2f Bullet::unitVector(sf::Vector2f source,
				sf::Vector2f target)
{
	sf::Vector2f unit_vector(target - source);

	float length = sqrt((unit_vector.x * unit_vector.x) + (unit_vector.y * unit_vector.y));
	if (length != 0)
		return sf::Vector2f(unit_vector.x / length, unit_vector.y / length);
	else
		return unit_vector;
}
