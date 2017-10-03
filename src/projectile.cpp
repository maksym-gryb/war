
#include "projectile.h"

Projectile::Projectile(sf::RenderWindow* p_window,
			Faction p_faction)
{
	_window = p_window;
	_faction = p_faction;
}

Projectile::~Projectile()
{}

void Projectile::update()
{
}

void Projectile::draw()
{
}
