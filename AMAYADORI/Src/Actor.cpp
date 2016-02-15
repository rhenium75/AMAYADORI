#pragma once
#include "../Actor.hpp"

Group::Group() {

}
bool Group::Infriend() {
	return false;
}
bool Group::Inenemy() {
	return false;
}


bool Actor::IsDeath() {
	return hp <= 0;
}
