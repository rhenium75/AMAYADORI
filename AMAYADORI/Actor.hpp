#pragma once
#include "AMAYADORI.hpp"

struct Group {
private:
	int Num;
	int Friend;
	int Enemy;
public:
	Group();
	bool Infriend();
	bool Inenemy();
};

class Actor {
public:
	Vec2 Pos;
	int hp;
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	virtual bool IsDeath();
};