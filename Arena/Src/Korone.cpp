#pragma once
#include <Siv3D.hpp>
#include "../Korone.hpp"

extern GameManager* GM;

namespace Korone {
	Korone::Korone(Team* t){
		team = t;
		body.SetLength(30)->SetPos(Vec2(0,500));
		SetType();
		korona = new Korona(team, body.GetPos());
		GM->AddCreature(korona);
		hp = Maxhp;
	}

	void Korone::Update() {
		frameCount++;
		Muteki--;
		hit--;
		korona->targetpos = body.GetPos() + Vec2(0,low?-40:0).rotate(body.GetAngle());
		korona->targetangle = body.GetAngle();
		low = Input::KeyShift.pressed;
		korona->low = low;
		MoveSpeed = low ? 5: 10;
		if(Roll == 59) SoundAsset(L"roll").playMulti();
		if (Roll < 0) sp = Min(sp+(low ? 4 : 2),1000);
	}
	void Korone::Draw()const {
		static int count = 0;
		static int name[3][4] = { { 1,2,1,2 }, {1,2,1,3 }, {1,2,1,2} };
		static int rollnum[3][3] = { {1,2,3},{1,2,3},{3,2,1} };
		if (frameCount % 8 == 0) {
			count = (count + 1) % 4;
		}
		TextureDraw(TextureAsset(L"hpeffect_r").resize(150, 150), frameCount / 100.,low?150:50 + sin(frameCount / 100.)*30);
		TextureDraw(TextureAsset(L"hpeffect_s").resize(80, 80), -frameCount / 100.,low?150:50 + sin(frameCount / 100.)*30);
		if (low) {
			hpbardraw(sp, Maxsp, 38, 3, { 230,230,0,240 });
			hpbardraw(hp, Maxhp, 65, 4, { 100,200,100,240 });
		}
		else {
			hpbardraw(sp, Maxsp, 38, 3, { 230,230,0,150 });
			hpbardraw(hp, Maxhp, 65, 4, { 100,200,100,150 });
		}
		
		if (Roll >= 39)
			TextureDraw(TextureAsset(L"koroneroll" + Format(rollnum[int(h)+1][(60 - Roll) / 7])).resize(60, 60));
		else
			TextureDraw(TextureAsset(L"korone" + Format(int(h)+1) +  Format(name[int(h)+1][count])).resize(60, 60));
	}


	int Korone::Damage(Actor *, int damage) {
		if (hit < 0) {
			hp = Max(hp - damage, 0);
			hit = 30;
			SoundAsset(L"death").playMulti();
		}
		return 0;
	}

	NormalBullet::NormalBullet(Team* t, Vec2 pos, Vec2 move){
		team = t;
		body.SetPos(pos)->SetForce(move)->SetAirResistance(0)->SetLength(50)->SetAnagle(Look(move)+HalfPi);
		SetType();
	}

	void NormalBullet::Attack() {
		for (auto&& actor : GM->GetBoss()) {
			if (team->Inenemy(actor->team->GetNum()) && body.Hit(actor->body)) {
				actor->AddForce(this,body.GetForce()/3);
				actor->Damage(this,100);
				hp = 0;
				GM->AddEffect(new HitEffect(body.GetPos(),body.GetAngle()));
				SoundAsset(L"firehit").playMulti();
			}
		}
		for (auto&& actor : GM->GetBullet()) {
			if (team->Inenemy(actor->team->GetNum()) && body.Hit(actor->body)) {
				actor->AddForce(this, body.GetForce()/3);
				actor->Damage(this, 100);
				hp = 0;
				GM->AddEffect(new HitEffect(body.GetPos(), body.GetAngle()));
				SoundAsset(L"firehit").playMulti();
			}
		}
	}
	
	void NormalBullet::Update() {
		frameCount++;
		if (frameCount % 5 == 0) imgcount = (imgcount + 1) % 4;
	}

	void NormalBullet::Draw() const{
		TextureDraw(TextureAsset(L"fire"+Format(imgcount+1)).resize(38*2,91*2));
	}

	HitEffect::HitEffect(Vec2 pos,double angle) {
		body.SetPos(pos+Vec2(0,-100).rotate(angle))->SetAnagle(angle);
	}

	bool HitEffect::IsDeath() {
		frameCount+=2;
		return frameCount > 31;
	}

	void HitEffect::Draw() const {
		TextureDraw(TextureAsset(L"firehit"+Format(frameCount/8+1)).resize(38 * 3, 91 * 3));
	}

	Korona::Korona(Team * _team, Vec2 pos) {
		team = _team;
		SetType();
		body.SetPos(pos)->SetLength(50);
		targetpos = pos;
		targetangle = 0;
	}

	void Korona::SetType() {
		type = TYPE_Creture;
		target_of_attack = 0;
		target_of_physics = 0;
	}

	void Korona::Update() {
		frameCount++;
		charge++;
		if (low || body.GetPos().distanceFrom(targetpos) > 40) {
			body.AddPos((targetpos - body.GetPos()) / (low ? 2 : 10));
		}
		body.AddAngle((targetangle - body.GetAngle()) / (low ? 2 : 5));
		if (Input::MouseL.pressed && charge > 20) {
			charge = 0;
			SoundAsset(L"firehit").playMulti();
			GM->AddBullet(new NormalBullet(team->copy(), body.GetPos(), Vec2(0, -15).rotate(body.GetAngle())));
		}
	}

	void Korona::Draw() const {
		int num[4] = {1,2,1,3};
		TextureDraw(TextureAsset(L"korona"+Format(num[(frameCount/7)%4])).resize(50, 50));
	}

}