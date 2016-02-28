#pragma once
#include <Siv3D.hpp>
#include "../GameManager.hpp"
#include "../Actor.hpp"

extern GameManager* GM;

Actor::Actor() {
}

void Actor::SetType() {
}

void Actor::Update(){
}

void Actor::Move(){
	body.Update();
}


void Actor::Attack(){
}

void Actor::CameraDraw(Vec2 pos, double angle) {
	CenterPos = pos;
	CenterAngle = angle;
	Draw();
}

void Actor::TextureDraw(const Texture texture)const {
	texture.rotate(body.GetAngle()-CenterAngle).drawAt((body.GetPos()-CenterPos).rotate(-CenterAngle));
}

void Actor::TextureDraw(const TextureRegion texture)const {
	texture.rotate(body.GetAngle()-CenterAngle).drawAt((body.GetPos() - CenterPos).rotate(-CenterAngle));
}
void Actor::TextureDraw(const TextureRegion texture,double angle,int alpha) const {
	texture.rotate(body.GetAngle() - CenterAngle+angle).drawAt((body.GetPos() - CenterPos).rotate(-CenterAngle),Alpha(alpha));
}
void Actor::TextureDraw_NoRotate(const Texture texture)const {
	texture.drawAt((body.GetPos() - CenterPos).rotate(-CenterAngle));
}
void Actor::TextureDraw_NoRotate(const TextureRegion texture)const {
	texture.drawAt((body.GetPos() - CenterPos).rotate(-CenterAngle));
}

int Actor::Damage(Actor *, int damage) {
	hp -= damage;
	return damage;
}

bool Actor::AddForce(Actor *, Vec2 force) {
	body.AddForce(force);
	return true;
}

bool Actor::IsDeath() {
	return hp <= 0;
}

void Actor::hpbardraw(int _hp, int _maxhp, double r, double w, Color c) const {
	Circle((body.GetPos() - CenterPos).rotate(-CenterAngle)).setSize(r).drawArc(TwoPi-TwoPi*_hp / _maxhp, TwoPi*_hp/_maxhp,w,0,c);
}


Player::Player() {
	SetType();
}

void Player::Move() {
	Actor::Move();
	Roll--;
	if (Roll <= 40) {
		double v = int(Input::KeyS.pressed || Input::KeyDown.pressed) - int(Input::KeyW.pressed || Input::KeyUp.pressed);
		h = int(Input::KeyD.pressed || Input::KeyRight.pressed) - int(Input::KeyA.pressed || Input::KeyLeft.pressed);
		double moveAngle;
		if (v != 0 || h != 0) {
			moveAngle = Atan2(v, h) + body.GetAngle();
			body.AddPos(Vec2(MoveSpeed, 0).rotate(moveAngle));
		}
		else {
			moveAngle = body.GetAngle()-HalfPi;
		}
		if (Roll <= 0 && (Input::KeySpace.clicked || Input::MouseR.clicked)) {
			Muteki = 30;
			Roll = 60;
			body.AddForce(Vec2(30, 0).rotate(moveAngle));
		}
	}
	body.AddAngle(Clamp((Mouse::Pos().x - 320) / 600., -0.1, 0.1));
	Cursor::SetPos(320, 240);
}

int Player::Damage(Actor *, int damage) {
	if (Muteki > 0) return 0;
	hp -= damage;
	return damage;
}

bool Player::AddForce(Actor *, Vec2 force) {
	if(Muteki > 0)return false;
	body.AddForce(force);
	return true;
}

void Player::SetType() {
	type = TYPE_Boss;
	target_of_attack = 0;
	target_of_physics = TYPE_Boss | TYPE_Creture | TYPE_Building;
}


EnemyBoss::EnemyBoss() {
	SetType();
}

void EnemyBoss::SetType() {
	type = TYPE_Boss;
	target_of_attack = TYPE_Boss;
	target_of_physics = TYPE_Boss | TYPE_Creture | TYPE_Building;
}

Bullet::Bullet() {
	SetType();
}

void Bullet::SetType() {
	type = TYPE_Bullet;
	target_of_attack = TYPE_Boss | TYPE_Creture;
	target_of_physics = TYPE_Boss | TYPE_Creture | TYPE_Building;
}

EnemyCreture::EnemyCreture() {
	SetType();
}

void EnemyCreture::SetType() {
	type = TYPE_Creture;
	target_of_attack = TYPE_Boss;
	target_of_physics = TYPE_Boss | TYPE_Creture | TYPE_Building;
}
