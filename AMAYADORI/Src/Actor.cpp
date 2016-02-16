#pragma once
#include <Siv3D.hpp>
#include "../Actor.hpp"

Actor::Actor() {
}

bool Actor::IsDeath() {
	return hp <= 0;
}

void Player::Update() {
}