#include "../StageKinako.hpp"

extern GameManager* GM;

StageKinako::StageKinako() {
	PlayerTeam = (new Team())->SetNum(TEAM_Player)->SetEnemy(TEAM_Enemy);
	EnemyTeam = (new Team())->SetNum(TEAM_Enemy)->SetEnemy(TEAM_Player);
	player = new Korone::Korone(EnemyTeam);
	boss = new Kinako::Kinako(PlayerTeam);
	GM->AddBoss(player);
	GM->AddBoss(boss);
	camera.init(GM,player);
	SoundAsset(L"kinakobgm").setLoop(true);
	SoundAsset(L"kinakobgm").play();
}

void StageKinako::Update() {
	camera.update();
	GM->All_Update();
}

void StageKinako::Draw() const {
	camera.draw();
	Graphics2D::SetTransform(Mat3x2::Translate(Vec2(320, 350)));
	double angle = Look(player->body.GetPos(),boss->body.GetPos());
	Circle(Vec2(-100,0).rotate(angle-player->body.GetAngle())).setSize(10).draw();
}
