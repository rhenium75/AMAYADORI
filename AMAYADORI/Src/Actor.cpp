#pragma once
#include "../Hdf/Actor.hpp"

void Actor::Update() {
}

void Actor::Draw()const {

}

bool Actor::IsDeath() {
	return hp <= 0;
}