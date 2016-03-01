#pragma once
#include "Declaration.hpp"

namespace Korone{
	class Korona;
	class Korone : public Player {
	public:
		Korona* korona;
		Korone(Team*);
		void Update()override;
		void Draw()const override;
		int Damage(Actor*, int)override;
	};

	class Korona : public Actor {
	public:
		Vec2 targetpos;
		double targetangle;
		int charge = 0;
		bool low = false;
		Korona(Team*,Vec2);
		void SetType()override;
		void Update()override;
		void Draw()const override;
	};

	class NormalBullet : public Bullet {
	public:
		int imgcount = 0;
		NormalBullet(Team*,Vec2,Vec2);
		void Attack()override;
		void Update()override;
		void Draw()const override;
	};

	class HitEffect : public Actor {
	public:
		HitEffect(Vec2, double);
		bool IsDeath()override;
		void Draw()const override;
	};
}