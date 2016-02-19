#pragma once
#include "../AMAYADORI/AMAYADORI.hpp"


extern GameManager *GM = new GameManager();

void Arena_Setup() {
	TextureAsset::Register(L"korone", L"Arena/Data/korone.png");
	TextureAsset::Register(L"sword", L"Arena/Data/sword.png");
	TextureAsset::Register(L"stage", L"Arena/Data/Stage.png");
}
