#pragma once
#include "Declaration.hpp"


extern GameManager *GM = new GameManager();

void Arena_Setup() {
	//GM = new GameManager();

	//Texture

	TextureAsset::Register(L"title", L"Data/title.png");

	TextureAsset::Register(L"gamestart", L"Data/gamestart.png");
	TextureAsset::Register(L"gameover", L"Data/gameover.png");
	TextureAsset::Register(L"gameclear", L"Data/gameclear.png");

	TextureAsset::Register(L"koroneselect", L"Data/koroneselect.png");

	TextureAsset::Register(L"korone11", L"Data/korone1.png");
	TextureAsset::Register(L"korone12", L"Data/korone2.png");
	TextureAsset::Register(L"korone13", L"Data/korone3.png");

	TextureAsset::Register(L"korone01", L"Data/koroneleft1.png");
	TextureAsset::Register(L"korone02", L"Data/koroneleft2.png");

	TextureAsset::Register(L"korone21", L"Data/koroneright1.png");
	TextureAsset::Register(L"korone22", L"Data/koroneright2.png");
	
	TextureAsset::Register(L"koroneroll1", L"Data/koronerollleft.png");
	TextureAsset::Register(L"koroneroll2", L"Data/koronerollback.png");
	TextureAsset::Register(L"koroneroll3", L"Data/koronerollright.png");

	TextureAsset::Register(L"korona1", L"Data/korona1.png");
	TextureAsset::Register(L"korona2", L"Data/korona2.png");
	TextureAsset::Register(L"korona3", L"Data/korona3.png");


	TextureAsset::Register(L"fire1", L"Data/fire1.png");
	TextureAsset::Register(L"fire2", L"Data/fire2.png");
	TextureAsset::Register(L"fire3", L"Data/fire3.png");
	TextureAsset::Register(L"fire4", L"Data//fire4.png");
	TextureAsset::Register(L"firehit1", L"Data//firehit1.png");
	TextureAsset::Register(L"firehit2", L"Data//firehit2.png");
	TextureAsset::Register(L"firehit3", L"Data//firehit3.png");
	TextureAsset::Register(L"firehit4", L"Data//firehit4.png");

	TextureAsset::Register(L"hpeffect_s", L"Data//hpeffect_s.png");
	TextureAsset::Register(L"hpeffect_r", L"Data//hpeffect_r.png");

	TextureAsset::Register(L"sword", L"Data//sword.png");
	
	TextureAsset::Register(L"kinako", L"Data//Kinako.png");
	TextureAsset::Register(L"rock1", L"Data//rock1.png");
	TextureAsset::Register(L"rock2", L"Data//rock2.png");
	TextureAsset::Register(L"rock3", L"Data//rock3.png");
	
	TextureAsset::Register(L"garnet", L"Data//garnet.png");
	
	TextureAsset::Register(L"stage", L"Data//Stage.png");
	TextureAsset::Register(L"stageload", L"Data//stageload.png");
	
	TextureAsset::PreloadAll();

	//Sound

	SoundAsset::Register(L"titlebgm", L"Data/BGM/bgm1.mp3");
	SoundAsset::Register(L"kinakobgm", L"Data/BGM/bgm3.mp3");

	SoundAsset::Register(L"selectcursor", L"Data/SE/select_cursor.mp3");
	SoundAsset::Register(L"selectenter", L"Data/SE/select_ok.mp3");

	SoundAsset::Register(L"fire", L"Data/SE/set/tm2_wood004.mp3");
	SoundAsset::Register(L"roll", L"Data/SE/set/tm2_shake001.mp3");
	SoundAsset::Register(L"rock", L"Data/SE/set/tm2_wood003.mp3");

	SoundAsset::PreloadAll();
}

/*Music() {
    BGM = new AudioPlayer[4];
    BGM[0] = minim.loadFile("data/Music/BGM/bgm1.mp3");
    BGM[1] = minim.loadFile("data/Music/BGM/bgm4.mp3");
    BGM[2] = minim.loadFile("data/Music/BGM/bgm2.mp3");
    BGM[3] = minim.loadFile("data/Music/BGM/bgm3.mp3");
    SE = new AudioSample[14];
    SE[0] = minim.loadSample("data/Music/SE/select_ok.mp3");
    SE[1] = minim.loadSample("data/Music/SE/SE2.mp3");
    SE[2] = minim.loadSample("data/Music/SE/set/tm2_shoot000.mp3");
    SE[3] = minim.loadSample("data/Music/SE/set/tm2_scratch000.mp3");
    SE[4] = minim.loadSample("data/Music/SE/set/tm2_death000.mp3");
    SE[5] = minim.loadSample("data/Music/SE/set/tm2_power001.mp3");
    SE[6] = minim.loadSample("data/Music/SE/set/tm2_bom000.mp3");
    SE[7] = minim.loadSample("data/Music/SE/set/tm2_bom001.mp3");
    SE[8] = minim.loadSample("data/Music/SE/set/tm2_laser002.mp3");
    SE[9] = minim.loadSample("data/Music/SE/set/tm2_clock000.mp3");
    SE[10] = minim.loadSample("data/Music/SE/set/tm2_wood003.mp3");
    SE[11] = minim.loadSample("data/Music/SE/set/tm2_power000.mp3");
    SE[12] = minim.loadSample("data/Music/SE/set/tm2_gun001.mp3");
    SE[13] = minim.loadSample("data/Music/SE/set/tm2_hit001.mp3");
  }*/