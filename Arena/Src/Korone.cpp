#pragma once
#include <Siv3D.hpp>
#include "../Korone.hpp"

extern GameManager* GM;

namespace Korone {
	Korone::Korone(Team t){
		team = t;
		body.Length = 30;
	}

	void Korone::Update() {
		frameCount++;
		if (Input::MouseL.clicked) {
			GM->AddBullet(new NormalBullet(team.copy(),Pos,Vec2(0,-5)));
		}
	}

	void Korone::Attack(){
	}

	void Korone::Draw()const {
		static int count = 0;
		static int name[4] = { 1,2,1,3 };
		if (frameCount % 8 == 0) {
			count = (count + 1) % 4;
		}
		TextureAsset(L"korone"+Format(name[count])).resize(60, 60).drawAt(Pos);
	}

	NormalBullet::NormalBullet(Team t, Vec2 pos, Vec2 move){
		team = t;
		Pos = pos;
		Force = move;
		AirResistance = 0;
	}
	
	void NormalBullet::Update() {
		frameCount++;
		if (frameCount % 5 == 0) imgcount = (imgcount + 1) % 4;
	}

	void NormalBullet::Draw() const{
		TextureAsset(L"fire"+Format(imgcount+1)).resize(38,91).drawAt(Pos);
	}

}