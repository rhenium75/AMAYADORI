#include "../StageKinako.hpp"

extern GameManager* GM;

StageKinako::StageKinako() {
	GM = new GameManager();
	PlayerTeam = (new Team())->SetNum(TEAM_Player)->SetEnemy(TEAM_Enemy);
	EnemyTeam = (new Team())->SetNum(TEAM_Enemy)->SetEnemy(TEAM_Player);
	player = new Korone::Korone(EnemyTeam);
	boss = new Kinako::Kinako(PlayerTeam,player);
	GM->AddBoss(player);
	GM->AddBoss(boss);
	camera.init(GM,player);
	SoundAsset(L"kinakobgm").setLoop(true);
	SoundAsset(L"kinakobgm").play();
}

void StageKinako::Update() {
	camera.update();
	GM->All_Update();
	for (auto&& actor : GM->GetBoss())
		actor->body.SetPos(Vec2(Clamp(actor->body.GetPos().x,-500.,500.), Clamp(actor->body.GetPos().y, -500., 500.)));
}

void StageKinako::Draw() const {
	camera.draw(&TextureAsset(L"stageload"));
	Graphics2D::SetTransform(Mat3x2::Translate(Vec2(320, 350)));
	if (!camera.ViewField.Hit(boss->body)) {
		double angle = Look(player->body.GetPos(), boss->body.GetPos());
		Triangle(Vec2(-100, 0).rotate(angle - player->body.GetAngle()), 30.).rotated(angle - player->body.GetAngle()+0.5).draw({200,0,0,100});
	}
}

void StageKinako::Exit() {
	SoundAsset(L"kinakobgm").stop();
}
