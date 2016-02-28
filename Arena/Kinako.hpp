#pragma once
#include "Declaration.hpp"

extern GameManager* GM;

namespace Kinako {

	class Kinako : public EnemyBoss {
	public:
		int pattern = 0;
		Kinako(Team*);
		void Move()override;
		void Update()override;
		void Attack()override;
		void Draw()const override;
	};

	class BreakRock1 : public EnemyCreture {
	public:
		BreakRock1(Team*, Vec2, Vec2);
		void Draw()const override;
	};
}