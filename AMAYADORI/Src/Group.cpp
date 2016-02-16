#pragma once
#include "../Group.hpp"

inline int GroupNum(int num) {
	return 1 << num;
}

Group::Group() {
	Group(0,0,0);
}

Group::Group(int _num) {
	Group(_num, 0, 0);
}

Group::Group(int _num, int enemynum) {
	Group(_num, enemynum, 0);
}

Group::Group(int _num, int enemynum, int friendnum) {
	Num = GroupNum(_num);
	Enemy = enemynum;
	Friend = friendnum;
}

void Group::SetNum(int num){
	Num = num;
}

void Group::SetEnemy(int enemy){
	Enemy = enemy;
}

void Group::SetFriend(int _friend){
	Friend = _friend;
}

void Group::AddEnemy(int enemy){
	Enemy |= enemy;
}

void Group::AddFriend(int){
}

bool Group::Infriend(int g) {
	return Friend & g;
}

bool Group::Inenemy(int g) {
	return Enemy & g;
}

Group Group::copy() {
	return Group(Num,Friend,Enemy);
}

int Group::operator()() {
	return Num;
}