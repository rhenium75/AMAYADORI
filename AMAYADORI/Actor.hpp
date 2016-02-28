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
	Vec2 CenterPos;
	double CenterAngle;
public:
	Body body;

	Team* team;
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
	void CameraDraw(Vec2,double);
	void TextureDraw(const Texture)const;
	void TextureDraw(const TextureRegion)const;
	void TextureDraw(const TextureRegion,double,int)const;
	void TextureDraw_NoRotate(const Texture)const;
	void TextureDraw_NoRotate(const TextureRegion)const;

	virtual int Damage(Actor*,int);
	virtual bool AddForce(Actor*,Vec2);

	virtual bool IsDeath();
	void hpbardraw(int, int, double,double, Color)const;
};

class Player : public Actor {
public:
	bool low = false;
	int Maxhp = 5000;
	int sp = 1000;
	int Maxsp = 1000;
	int Muteki = 0;
	int Roll = 0;
	double h;
	Player();
	double MoveSpeed = 10;
	virtual void Move();
	int Damage(Actor*,int)override;
	bool AddForce(Actor*,Vec2)override;
	void SetType()override;
};

class EnemyBoss : public Actor {
public:
	EnemyBoss();
	void SetType()override;
};

class EnemyCreture : public Actor {
public:
	EnemyCreture();
	void SetType()override;
};

class Bullet : public Actor {
public:
	Bullet();
	void SetType()override;
};
