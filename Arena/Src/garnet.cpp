#include "../garnet.hpp"

extern GameManager *GM;

namespace Garnet {
	Garnet::Garnet(Team g){
		team = g;
	}

	void Garnet::Move() {
		static double ss = 0;
		ss += 0.05;
		Pos.set(300+cos(ss)*100,300+sin(ss)*100);
		//Pos += (GM->GetBoss()[0]->Pos - Pos) / 10;
	}

	void Garnet::Update(){
		frameCount++;
		FOR(i,10 && frameCount%90 == 0) {
			GM->AddBullet(new NormalBullet(team,Pos, Vec2(5, 0).rotate(i / 10.*TwoPi)));
		}
	}

	void Garnet::Draw() const{
		TextureAsset(L"garnet").drawAt(Pos);
	}

	NormalBullet::NormalBullet(Team g, Vec2 pos, Vec2 move) {
		team = g;
		Pos = pos;
		Force = move;
		AirResistance = 0;
		body.SetLength(10);
	}

	void NormalBullet::Update() {
		if (Pos.x < 0 || Pos.x > 800 || Pos.y < 0 || Pos.y > 500)
			hp = 0;
	}

	void NormalBullet::Draw() const {
		TextureAsset(L"sword").rotate(Atan2(Force.y,Force.x)+HalfPi).drawAt(Pos);
	}
}