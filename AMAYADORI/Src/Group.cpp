#pragma once
#include "../Group.hpp"


Team::Team() {
}

Team* Team::SetNum(int _num) {
	Num = _num;
	return this;
}

Team* Team::SetEnemy(int _enemy) {
	Enemy = _enemy;
	return this;
}

Team* Team::SetFriend(int _friend) {
	Friend = _friend;
	return this;
}

inline int TeamNum(int num) {
	return 1 << num;
}

void Team::AddEnemy(int enemy){
	Enemy |= enemy;
}

void Team::AddFriend(int _friend){
	Friend |= _friend;
}

int Team::GetNum() {
	return Num;
}

bool Team::Infriend(int t) {
	return Friend & t;
}

bool Team::Inenemy(int t) {
	return Enemy & t;
}

int Team::operator()() {
	return Num;
}

Team* Team::copy() {
	return ((new Team())->SetNum(Num)->SetFriend(Friend)->SetEnemy(Enemy));
}

inline int GroupNum(int num) {
	return 1 << num;
}
