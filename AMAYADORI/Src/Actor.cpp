#pragma once
#include "../Hdf/Actor.hpp"

bool Actor::IsDeath() {
	return hp <= 0;
}
