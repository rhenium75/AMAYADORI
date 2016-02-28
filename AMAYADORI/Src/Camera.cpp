#include "../Camera.hpp"
#include "..\Camera.hpp"

BigCamera::BigCamera() {
}

BigCamera::BigCamera(GameManager * gm, Actor* actor) {
	init(gm,actor);
}

void BigCamera::init(GameManager * gm, Actor* actor) {
	gamemanager = gm;
	target = actor;
	ViewField.SetPos(actor->body.GetPos())->SetAnagle(actor->body.GetAngle())->SetLength(500);
}

void BigCamera::update() {
	ViewField.AddPos((target->body.GetPos()-ViewField.GetPos())/3.);
	ViewField.AddAngle((target->body.GetAngle()-ViewField.GetAngle())/3.);
}

void BigCamera::draw(const Texture* t) const {
	Graphics2D::SetTransform(Mat3x2::Translate(Vec2(320,350)));
	t->rotateAt(Vec2(2450,2450) + ViewField.GetPos(),-ViewField.GetAngle()).drawAt(0,0);
	ActorDraw(&gamemanager->GetBuilding());
	ActorDraw(&gamemanager->GetItem());
	ActorDraw(&gamemanager->GetBullet());
	ActorDraw(&gamemanager->GetCreature());
	ActorDraw(&gamemanager->GetBoss());
	ActorDraw(&gamemanager->GetEffects());
}

void BigCamera::ActorDraw(Array<Actor*>* actors)const {
	for (auto&& actor : *actors)
		if(ViewField.Hit(actor->body))
			actor->CameraDraw(ViewField.GetPos(),ViewField.GetAngle());
}
