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
		BreakRock1(Team* _team, Vec2 pos, Vec2 force) {
			team = _team;
			SetType();
			target_of_physics |= TYPE_Bullet;
			body.SetPos(pos)->SetForce(force)->SetLength(50)->SetAirResistance(0.02);
			hp = 500;
		}
		virtual void Update()override;
		virtual void Draw()const override {
			TextureDraw(TextureAsset(L"rock1"));
		}
	};

	class BreakRock2 : public EnemyCreture {
	public:
		BreakRock2(Team* _team, Vec2 pos, Vec2 force) {
			team = _team;
			SetType();
			target_of_physics |= TYPE_Bullet;
			body.SetPos(pos)->SetForce(force)->SetLength(25)->SetAirResistance(0.02);
			hp = 300;
		}
		virtual void Draw()const override {
			TextureDraw(TextureAsset(L"rock2"));
		}
	};

	class AutoBreakRock : public EnemyCreture {
	public:
		AutoBreakRock(Team* _team, Vec2 pos, Vec2 force) {
			team = _team;
			SetType();
			target_of_physics |= TYPE_Bullet;
			body.SetPos(pos)->SetForce(force)->SetLength(50)->SetAirResistance(0.02);
			hp = 500;
		}
		virtual void Update()override;
		virtual void Draw()const override {
			TextureDraw(TextureAsset(L"rock1"));
		}
	};
}