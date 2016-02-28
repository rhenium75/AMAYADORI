#pragma once
#include "GameManager.hpp"
#include "Actor.hpp"

class BigCamera {
public:
	Actor* target;
	GameManager* gamemanager;
	Body ViewField;
	BigCamera();
	BigCamera(GameManager*, Actor*);
	void init(GameManager*, Actor*);
	void update();
	void draw()const;
	void ActorDraw(Array<Actor*>*)const;
};