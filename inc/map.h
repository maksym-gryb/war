#pragma once

#include "unit.h"
#include "projectile.h"

#include <list>

class Map{
	public:
		Map();
		~Map();

		void addUnit(Unit* p_unit);
		void addProjectile(Projectile* p_projectile);

		std::list<Unit*>::iterator unitBegin();
		std::list<Unit*>::iterator unitEnd();

		std::list<Projectile*>::iterator projectileBegin();
		std::list<Projectile*>::iterator projectileEnd();

	private:
		std::list<Unit*> _units;
		std::list<Projectile*> _projectiles;
};
