#pragma once
#include <Siv3D.hpp>
#include "../Actor.hpp"

Actor::Actor() {
	Pos.set(0, 0);
	Force.set(0, 0);
	group.SetNum(0);
}

void Actor::init(){
}

void Actor::Update(){
}

void Actor::Move(){
	Pos += Force;
	Force -= Force*AirResistance;
	init();
}

void Actor::Attack(){
}

bool Actor::IsDeath() {
	return hp <= 0;
}


void Player::Move(){
	Actor::Move();
	Pos += (Mouse::Pos() - Pos) / 10;
}
