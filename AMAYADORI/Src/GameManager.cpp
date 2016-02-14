#pragma once
#include "../Hdf/GameManager.hpp"
#include "../Hdf/Actor.hpp"

void GameManager::Update() {
	for (int i = 0; i < Boss.size();i++)
		Boss[i]->Update();
}


void GameManager::Draw()const {

}

void GameManager::AddBoss(Actor *actor){
	Boss.push_back(actor);
}
