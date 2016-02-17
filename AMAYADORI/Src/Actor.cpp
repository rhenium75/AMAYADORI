#pragma once
#include <Siv3D.hpp>
#include "../Actor.hpp"


void Actor::Update(){
}

void Actor::Move(){
	Pos += Force;
	Force -= Force*AirResistance;
}

void Actor::Attack(){
}

bool Actor::IsDeath() {
	return hp <= 0;
}

void Player::Move(){
	Actor::Move();
}
