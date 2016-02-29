#include "../Kinako.hpp"

namespace Kinako {

	Kinako::Kinako(Team* _team,Actor* _target) {
		team = _team;
		hp = 10000;
		body.SetLength(50);
		SetType();
		target = _target;
	}

	void Kinako::Move() {
		EnemyBoss::Move();
		if (pattern > 5 && body.GetPos().distanceFrom(Vec2(0, 0)) > 100) {
			AddForce(this, Vec2(-2, 0).rotate(Look(body.GetPos())));
		}
	}

	void Kinako::Update() {
		pattern = hp / 1000;
		frameCount++;
	}

	void Kinako::Attack() {
		ClearPrint();
		if (pattern > 8) {
			if (frameCount % 60 == 0) {
				double angle = Look((target->body.GetPos()-body.GetPos()))+HalfPi;
				GM->AddCreature(new AutoBreakRock(team->copy(), body.GetPos() + Vec2(0, -120).rotate(angle), Vec2(0, -1).rotate(angle)));
			}
		}
	}

	void Kinako::Draw() const {
		TextureDraw_NoRotate(TextureAsset(L"kinako"));
	}

	void BreakRock1::Update() {
		if (hp <= 100) {
			hp = 0;
			FOR(i,3)
				GM->AddCreature(new BreakRock2(team->copy(),body.GetPos()+RandomVec2(-10,10),RandomVec2(-20,20)));
		}
	}
	void AutoBreakRock::Update() {
		frameCount++;
		if (hp <= 100 || frameCount > 30) {
			hp = 0;
			FOR(i, 3)
				GM->AddCreature(new BreakRock2(team->copy(), body.GetPos() + RandomVec2(-10, 10), RandomVec2(-20, 20)));
		}
	}
}