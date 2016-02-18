#pragma once
#include <Siv3D.hpp>
#include "Korone.hpp"

namespace Korone {

	Korone::Korone(Group g) {
		group = g;
		hp = 100;
		Pos.set(100,100);
	}

	void Korone::Update() {
		Pos += (Mouse::Pos() - Pos) / 10;
		if (Input::MouseL.clicked) {
			//Arena::GM->AddBoss(new NormalBullet(Group(0),Pos,Vec2(0,-5)));
		}
	}

	void Korone::Attack(){
	}

	void Korone::Draw()const {
		TextureAsset(L"korone").resize(50, 50).drawAt(Pos);
	}

	NormalBullet::NormalBullet(Group g, Vec2 pos, Vec2 move){
		Pos = pos;
		Force = move;
		AirResistance = 0;
	}

	void NormalBullet::Draw() const{
		TextureAsset(L"sword").resize(30, 30).draw(Pos);
	}

}