#include "../Kinako.hpp"

namespace Kinako {

	Kinako::Kinako(Team* _team,Actor* _target) {
		team = _team;
		hp = 5000;
		body.SetLength(50)->SetPos(Vec2(0,-500));
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
		if (hp > 4000)pattern = 1;
		if (hp < 4000 && hp > 1500)pattern = 2;
		if (hp < 1500)pattern = 3;
		frameCount++;
	}

	void Kinako::Attack() {
		ClearPrint();
		if (pattern == 1) {
			if (frameCount % 60 == 0) {
				//Println(L"1");
				double angle = Look((target->body.GetPos()-body.GetPos()))+HalfPi;
				GM->AddCreature(new AutoBreakRock(team->copy(), body.GetPos() + Vec2(0, -120).rotate(angle), Vec2(0, -5).rotate(angle)));
			}
		}else if (pattern == 2) {
		///	Println(L"2");
			if (frameCount % 180 == 0) {
				double angle = Look((target->body.GetPos() - body.GetPos())) + HalfPi;
				GM->AddCreature(new AutoBreakRock(team->copy(), body.GetPos() + Vec2(0, -150).rotate(angle - QuarterPi), Vec2(0, -3).rotate(angle - QuarterPi)));
				GM->AddCreature(new AutoBreakRock(team->copy(), body.GetPos() + Vec2(0, -150).rotate(angle), Vec2(0, -3).rotate(angle)));
				GM->AddCreature(new AutoBreakRock(team->copy(), body.GetPos() + Vec2(0, -150).rotate(angle + QuarterPi), Vec2(0, -3).rotate(angle + QuarterPi)));
			}
			if (frameCount % 40 == 2) {
				double angle = Look((target->body.GetPos() - body.GetPos())) + HalfPi;
				FOR(i, 3)
					GM->AddBullet(new NormalBullet(team->copy(),body.GetPos(),Vec2(0,-2).rotate(i/3.*TwoPi+angle)));
			}
		}else if(pattern == 3){
			if (frameCount % 40 == 0) {
			//	Println(L"3");
				double angle = Look((target->body.GetPos() - body.GetPos())) + HalfPi;
				FOR(i, 3)
					GM->AddBullet(new NormalBullet(team->copy(), body.GetPos(), Vec2(0, -7).rotate(i / 3.*TwoPi + angle)));
				FOR(i, 5)
					GM->AddBullet(new NormalBullet(team->copy(), body.GetPos(), Vec2(0, -7).rotate(i / 5.*TwoPi + angle+QuarterPi)));
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
				GM->AddCreature(new BreakRock2(team->copy(),body.GetPos()+RandomVec2(100,100)-Vec2(50,50), RandomVec2(40, 40) - Vec2(20, 20)));
		}
	}
	void AutoBreakRock::Update() {
		frameCount++;
		if (hp <= 100 || frameCount > 30) {
			hp = 0;
			FOR(i, 3)
				GM->AddCreature(new BreakRock2(team->copy(), body.GetPos() + RandomVec2(100, 100) - Vec2(50, 50), RandomVec2(40, 40) - Vec2(20, 20)));
		}
	}
}