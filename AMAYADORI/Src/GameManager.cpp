#pragma once
#include "../GameManager.hpp"
#include "../Actor.hpp"
#define ActorProcess(actors,process) for(auto&& actor : actors) actor->process
#define ActorDeath(actors) for(int i = 0;i < actors.size();i++){ if(actors[i]->IsDeath()) { delete actors[i]; actors.erase(actors.begin()+i); i--; } }
#define FOR(i,l) for(int i = 0;i < l;i++)
#define PhysicsFOR(actor1, actor2, i, s) for (int j = s; j < actor2.size(); j++){if (actor1[i]->target_of_physics & actor2[j]->type){ Collision(actor1[i], actor2[j]);}}if(true)

void GameManager::All_Update() {
	Update();
	Attack();
	Move();
	Death();
	Physics();
}

void GameManager::Update() {
	ActorProcess(Boss, Update());
	ActorProcess(Creature, Update());
	ActorProcess(Bullet, Update());
	ActorProcess(Building, Update());
	ActorProcess(Item, Update());
}

void GameManager::Attack() {
	ActorProcess(Boss, Attack());
	ActorProcess(Creature, Attack());
	ActorProcess(Bullet, Attack());
	ActorProcess(Building, Attack());
	ActorProcess(Item, Attack());
}

void GameManager::Move() {
	ActorProcess(Boss, Move());
	ActorProcess(Creature, Move());
	ActorProcess(Bullet, Move());
	ActorProcess(Building, Move());
	ActorProcess(Item, Move());
}

void GameManager::Death() {
	ActorDeath(Boss);
	ActorDeath(Creature);
	ActorDeath(Bullet);
	ActorDeath(Building);
	ActorDeath(Item);
}

void GameManager::Physics() {
	FOR(i, Boss.size()) {
		PhysicsFOR(Boss, Boss, i, i+1);
		PhysicsFOR(Boss, Creature, i, 0);
		PhysicsFOR(Boss, Bullet, i, 0);
		PhysicsFOR(Boss, Building, i, 0);
		PhysicsFOR(Boss, Item, i, 0);
	}
	FOR(i, Creature.size()) {
		PhysicsFOR(Creature, Creature, i, i+1);
		PhysicsFOR(Creature, Bullet, i, 0);
		PhysicsFOR(Creature, Building, i, 0);
		PhysicsFOR(Creature, Item, i, 0);
	}
	FOR(i, Bullet.size()) {
		PhysicsFOR(Bullet, Bullet, i, i+1);
		PhysicsFOR(Bullet, Building, i, 0);
		PhysicsFOR(Bullet, Item, i, 0);
	}
	FOR(i, Building.size()) {
		PhysicsFOR(Building, Building, i, i+1);
		PhysicsFOR(Building, Item, i, 0);
	}
	FOR(i, Item.size()) {
		PhysicsFOR(Item, Item, i, i+1);
	}
}


void GameManager::Draw()const {
	ActorDraw(Bullet);
	ActorDraw(Creature);
	ActorDraw(Boss);
}

void GameManager::ActorDraw(Array<Actor*> actors)const {
	for (auto&& actor : actors)
		actor->Draw();
}

void GameManager::Collision(Actor* actor1,Actor* actor2) {
	Body body1 = actor1->GetBody();
	Body body2 = actor2->GetBody();
	body1.intersects(body2);
		//double angle = Atan2(actor1->Pos.y-actor2->Pos.y, actor1->Pos.x-actor2->Pos.x);
		//actor1->AddForce(actor2,Vec2(1,0).rotate(angle));
		//actor2->AddForce(actor1, Vec2(1, 0).rotate(angle+Pi));
	
}

void GameManager::AddBoss(Actor *actor){
	Boss.push_back(actor);
}

void GameManager::AddCreature(Actor *actor){
	Bullet.push_back(actor);
}

void GameManager::AddBullet(Actor *actor){
	Creature.push_back(actor);
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

Array<Actor*> GameManager::GetBuilding() {
	return Building;
}

Array<Actor*> GameManager::GetItem() {
	return Item;
}
