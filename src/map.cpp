#include "map.h"

Map::Map()
{}

Map::~Map()
{}

void Map::addUnit(Unit* p_unit)
{
	_units.push_back(p_unit);
}

void Map::addProjectile(Projectile* p_projectile)
{
	_projectiles.push_back(p_projectile);
}

std::list<Unit*>::iterator Map::unitBegin()
{
	return _units.begin();
}

std::list<Unit*>::iterator Map::unitEnd()
{
	return _units.end();
}

std::list<Projectile*>::iterator Map::projectileBegin()
{
	return _projectiles.begin();
}

std::list<Projectile*>::iterator Map::projectileEnd()
{
	return _projectiles.end();
}
