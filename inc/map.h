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
		std::list<Unit*>::iterator eraseUnit(std::list<Unit*>::iterator it);

		std::list<Projectile*>::iterator projectileBegin();
		std::list<Projectile*>::iterator projectileEnd();
		std::list<Projectile*>::iterator eraseProjectile(std::list<Projectile*>::iterator it);

	private:
		std::list<Unit*> _units;
		std::list<Projectile*> _projectiles;
};
