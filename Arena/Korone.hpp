#pragma once
#include "Declaration.hpp"

namespace Korone{

	class Korone : public Player {
	public:
		Korone(Team);
		void Update()override;
		void Attack()override;
		void Draw()const override;
	};

	class NormalBullet : public Bullet {
	public:
		int imgcount = 0;
		NormalBullet(Team,Vec2,Vec2);
		void Update()override;
		void Draw()const override;
	};
}