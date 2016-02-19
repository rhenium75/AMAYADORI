#pragma once
#include <Siv3D.hpp>
#include "Group.hpp"

class Actor {
private:
	//Actor() = default;
public:
	Vec2 Pos;
	Vec2 Force;
	double AirResistance = 0.1;
	Group group;
	int hp = 1;
	Actor();
	virtual void init();
	virtual void Update();
	virtual void Move();
	virtual void Attack();
	virtual void Draw()const = 0;
	virtual bool IsDeath();
};

class Player : public Actor {
public:
	double MoveSpeed = 1;
	void Move();
};

class Bullet : public Actor {

};