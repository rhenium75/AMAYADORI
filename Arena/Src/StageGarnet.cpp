#pragma once
#include "../StageGarnet.hpp"
#define TEAM_None 0
#define TEAM_Player 1
#define TEAM_Enemy 2

extern GameManager* GM;

StageGarnet::StageGarnet() {;
	PlayerTeam = ((new Team())->SetNum(TEAM_Enemy)->SetEnemy(TEAM_Enemy));
	EnemyTeam = ((new Team())->SetNum(TEAM_Enemy)->SetEnemy(TEAM_Player));
	player = new Korone::Korone(PlayerTeam);
	boss = new Garnet::Garnet(EnemyTeam);
	GM->AddBoss(player);
	GM->AddBoss(boss);

	camera.init(GM,player);
}

void StageGarnet::Update() {
	camera.update();
	GM->All_Update();
}

void StageGarnet::Draw() const {
	camera.draw();
}


