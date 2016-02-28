#include "../Kinako.hpp"

namespace Kinako {

	Kinako::Kinako(Team* _team) {
		team = _team;
		hp = 10000;
		body.SetLength(50);
		SetType();
	}

	void Kinako::Move() {
		EnemyBoss::Move();
		if (pattern > 5 && body.GetPos().distanceFrom(Vec2(0,0)) > 100) {
			AddForce(this, Vec2(-2, 0).rotate(Look(body.GetPos())));
		}
	}

	void Kinako::Update() {
		pattern = hp / 1000;
		frameCount++;
	}

	void Kinako::Attack() {
		if (pattern > 8) {
			if (frameCount % 100 == 0)
				GM->AddCreature(new BreakRock1(team->copy(),body.GetPos(),Vec2(0,-30).rotate(body.GetAngle())));
		}
	}

	void Kinako::Draw() const {
		TextureDraw_NoRotate(TextureAsset(L"kinako"));
	}

	BreakRock1::BreakRock1(Team * _team, Vec2 pos, Vec2 force) {
		team = _team;
		SetType();
		target_of_physics |= TYPE_Bullet;
		body.SetPos(pos)->SetForce(force)->SetLength(50)->SetAirResistance(0.02);
	}

	void BreakRock1::Draw() const {
		TextureDraw(TextureAsset(L"rock1"));
	}

}