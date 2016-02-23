#pragma once
#include "Declaration.hpp"


extern GameManager *GM = new GameManager();

void Arena_Setup() {
	GM = new GameManager();
	TextureAsset::Register(L"korone1", L"Arena/Data/korone1.png");
	TextureAsset::Register(L"korone2", L"Arena/Data/korone2.png");
	TextureAsset::Register(L"korone3", L"Arena/Data/korone3.png");
	TextureAsset::Register(L"fire1", L"Arena/Data/fire1.png");
	TextureAsset::Register(L"fire2", L"Arena/Data/fire2.png");
	TextureAsset::Register(L"fire3", L"Arena/Data/fire3.png");
	TextureAsset::Register(L"fire4", L"Arena/Data/fire4.png");
	TextureAsset::Register(L"sword", L"Arena/Data/sword.png");
	TextureAsset::Register(L"garnet", L"Arena/Data/garnet.png");
	TextureAsset::Register(L"stage", L"Arena/Data/Stage.png");

	TextureAsset::PreloadAll();
}
