#pragma once
#include "../Actor.hpp"

bool Actor::IsDeath() {
	return hp <= 0;
}
