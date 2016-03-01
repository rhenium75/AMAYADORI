#include "../StageKinako.hpp"

extern GameManager* GM;

StageKinako::StageKinako() {
	delete GM;
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
	SoundAsset(L"gamestart").playMulti();
}

void StageKinako::Update() {
	camera.update();
	GM->All_Update();
	for (auto&& actor : GM->GetBoss())
		actor->body.SetPos(Vec2(Clamp(actor->body.GetPos().x,-750.,750.), Clamp(actor->body.GetPos().y, -750., 750.)));
	if ((boss->hp <= 0 || player->hp <= 0) && gameendframe == 0) {
		SoundAsset(L"gameend").playMulti();
		gameendframe = 50;
		if (player->hp <= 0) win = false;
		else if (boss->hp <= 0) win = true;
	}
	if (gameendframe > 1) gameendframe--;
}

void StageKinako::Draw() const {
	camera.draw(&TextureAsset(L"stage"));
	Graphics2D::SetTransform(Mat3x2::Translate(Vec2(320, 350)));
	if (!camera.ViewField.Hit(boss->body)) {
		double angle = Look((boss->body.GetPos()- player->body.GetPos()))+Pi;
		Triangle(Vec2(-100, 0).rotate(angle - player->body.GetAngle()), 30.).rotated(angle - player->body.GetAngle()+0.5).draw({200,0,0,100});
	}
	if (gameendframe > 0) {
		if (win) TextureAsset(L"gameclear").drawAt(0,0);
		else TextureAsset(L"gameover").drawAt(0,0);
	}
}

void StageKinako::Exit() {
	SoundAsset(L"kinakobgm").stop();
}
