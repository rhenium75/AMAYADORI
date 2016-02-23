#pragma once
#include <Siv3D.hpp>
#include "../GameManager.hpp"
#include "../Actor.hpp"

extern GameManager* GM;

Actor::Actor() {
	Pos.set(0, 0);
	Force.set(0, 0);
	body.SetPos(&Pos).SetLength(50);
	team.SetNum(0);
	SetType();
}

void Actor::SetType() {
}

void Actor::Update(){
}

void Actor::Move(){
	Pos += Force;
	Force -= Force*AirResistance;
}


void Actor::Attack(){
}

Body Actor::GetBody() {
	return body;
}

int Actor::Damage(Actor *, int damage) {
	hp -= damage;
	return damage;
}

bool Actor::AddForce(Actor *, Vec2 force) {
	Force += force;
	return true;
}

bool Actor::IsDeath() {
	return hp <= 0;
}


Player::Player() {
	SetType();
}

void Player::Move(){
	Actor::Move();
	Pos += (Mouse::Pos() - Pos) / 10;
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
