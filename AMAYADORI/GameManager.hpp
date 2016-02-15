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
	void AddBoss(Actor*);
};