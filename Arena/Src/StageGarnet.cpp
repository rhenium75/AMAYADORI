#pragma once
#include "../StageGarnet.hpp"
#define TEAM_None 0
#define TEAM_Player 1
#define TEAM_Enemy 2

extern GameManager* GM;

StageGarnet::StageGarnet() {
	player = new Korone::Korone(Team().SetNum(TEAM_Player));
	boss = new Garnet::Garnet(Team().SetNum(TEAM_Enemy));
	GM->AddBoss(player);
	GM->AddBoss(boss);
}

void StageGarnet::Update() {
	GM->All_Update();
}

void StageGarnet::Draw() const {
	static double ro = 0;
	ro += 0.01;
	TextureAsset(L"stage").rotate(ro).drawAt(100,100);
	GM->Draw();
}


