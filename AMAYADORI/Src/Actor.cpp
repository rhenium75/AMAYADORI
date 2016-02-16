#pragma once
#include "../Actor.hpp"

Actor::Actor() {
}

bool Actor::IsDeath() {
	return hp <= 0;
}
