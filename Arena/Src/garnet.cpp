#include "../garnet.hpp"

extern GameManager *GM;

namespace Garnet {
	Garnet::Garnet(Team* g){
		team = g;
		SetType();
	}

	void Garnet::Move() {
		EnemyBoss::Move();
		static double ss = 0;
		ss += 0.3;
		//Pos += Vec2(10,0).rotate(sin(ss));
		//Pos += (GM->GetBoss()[0]->Pos - Pos) / 10;
	}

	void Garnet::Update(){
		frameCount++;
		FOR(i,30 && frameCount%40 == 0) {
			GM->AddBullet(new NormalBullet(team,body.GetPos(), Vec2(10, 0).rotate(i / 30.*TwoPi)));
		}
	}

	void Garnet::Draw() const{
		TextureDraw_NoRotate(TextureAsset(L"garnet"));
	}

	NormalBullet::NormalBullet(Team* g, Vec2 pos, Vec2 move) {
		team = g;
		body.SetPos(pos)->SetForce(move)->SetAirResistance(0)->SetLength(10);
		SetType();
	}

	void NormalBullet::Update() {
		body.SetAnagle(Look(body.GetForce()) + HalfPi);
		Vec2 Pos = body.GetPos();
		if (Pos.x < -2000 || Pos.x > 2000 || Pos.y < -2000 || Pos.y > 2000)
			hp = 0;
	}

	void NormalBullet::Attack() {
		Array<Actor*> boss = GM->GetBoss();
		for (auto&& actor : boss) {
			Team t = *actor->team;
			if ( body.Hit(actor->body)) {
				actor->AddForce(this,Vec2(0,-2).rotate(body.GetAngle()));
			}
		}
	}

	void NormalBullet::Draw() const {
		TextureDraw(TextureAsset(L"sword"));
	}
}