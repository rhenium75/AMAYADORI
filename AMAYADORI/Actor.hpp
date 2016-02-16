#pragma once
#include <Siv3D.hpp>
#include "Group.hpp"

class Actor {
public:
	Vec2 Pos;
	Group group;
	int hp = 1;
	Actor();
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	virtual bool IsDeath();
};

class Player : public Actor {
public:
	void Update()override;
};