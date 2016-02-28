#pragma once
#include "Declaration.hpp"

namespace Garnet {
	class Garnet : public EnemyBoss {
	public:
		int frameCount;
		Garnet(Team*);
		void Move()override;
		void Update()override;
		void Draw()const override;
	};

	class NormalBullet : public Bullet {
	public:
		NormalBullet(Team*, Vec2, Vec2);
		void Update()override;
		void Attack()override;
		void Draw()const override;
	};
}