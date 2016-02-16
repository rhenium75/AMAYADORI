#pragma once
#include "../GameManager.hpp"
#include "../Actor.hpp"

void GameManager::Update() {
	ActorUpdate(Boss);
	ActorUpdate(Creature);
	ActorUpdate(Bullet);
}

void GameManager::ActorUpdate(Array<Actor*> actors) {
	for (auto&& actor : actors)
		actor->Update();
	Erase_if(actors, [](Actor* actor) { return actor->IsDeath(); });
}


void GameManager::Draw()const {
	ActorDraw(Boss);
	ActorDraw(Creature);
	ActorDraw(Bullet);
}

void GameManager::ActorDraw(Array<Actor*> actors)const {
	for (auto&& actor : actors)
		actor->Draw();
}

void GameManager::AddBoss(Actor *actor){
	Boss.push_back(actor);
}

Array<Actor*> GameManager::GetBoss() {
	return Boss;
}

Array<Actor*> GameManager::GetCreature() {
	return Creature;
}

Array<Actor*> GameManager::GetBullet() {
	return Bullet;
}