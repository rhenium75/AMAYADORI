#pragma once
#include <Siv3D.hpp>
#include "Group.hpp"
#include "Body.hpp"
#define TYPE_Boss 1
#define TYPE_Creture 2
#define TYPE_Bullet 4
#define TYPE_Building 8
#define TYPE_Item 16

class Actor {
private:
	//Actor() = default;
public:
	Vec2 Pos;
	Vec2 Force;
	Body body;
	double AirResistance = 0.1;

	Team team;
	int frameCount = 0;
	int type = 0;
	int target_of_attack = 0;
	int target_of_physics = 0;
	int hp = 1;
	
	Actor();
	virtual void SetType();
	virtual void Update();
	virtual void Move();
	virtual void Attack();
	virtual void Draw()const = 0;

	virtual Body GetBody();

	virtual int Damage(Actor*,int);
	virtual bool AddForce(Actor*,Vec2);

	virtual bool IsDeath();
};

class Player : public Actor {
public:
	Player();
	double MoveSpeed = 1;
	virtual void Move();
	void SetType()override;
};

class EnemyBoss : public Actor {
public:
	EnemyBoss();
	void SetType()override;
};

class Bullet : public Actor {
public:
	Bullet();
	void SetType()override;
};