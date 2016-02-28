#pragma once
#include <Siv3D.hpp>

class Actor;

class GameManager {
private:
	Array<Actor*> Boss;
	Array<Actor*> Creature;
	Array<Actor*> Bullet;
	Array<Actor*> Building;
	Array<Actor*> Item;
	Array<Actor*> Effects;
public:
	void All_Update();
	void Update();
	void Attack();
	void Move();
	void Death();
	void Physics();
	void Draw()const;
	void ActorDraw(Array<Actor*>)const;

	void Collision(Actor*,Actor*);
	
	void AddBoss(Actor*);
	void AddCreature(Actor*);
	void AddBullet(Actor*);
	void AddEffect(Actor*);

	Array<Actor*> GetBoss();
	Array<Actor*> GetCreature();
	Array<Actor*> GetBullet();
	Array<Actor*> GetBuilding();
	Array<Actor*> GetItem();
	Array<Actor*> GetEffects();
};