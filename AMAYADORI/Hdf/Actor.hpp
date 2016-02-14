#pragma once
#include "../AMAYADORI.hpp"

class Actor {
public:
	Vec2 Pos;
	int hp;
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	virtual bool IsDeath();
};