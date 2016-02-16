#pragma once
#include <Siv3D.hpp>

class Actor;

class GameManager {
private:
	Array<Actor*> Boss;
	Array<Actor*> Creature;
	Array<Actor*> Bullet;
public:
	void Update();
	void Draw()const;
	void ActorDraw(Array<Actor*>)const;
	void AddBoss(Actor*);
	void ActorUpdate(Array<Actor*>);
	Array<Actor*> GetBoss();
	Array<Actor*> GetCreature();
	Array<Actor*> GetBullet();
};