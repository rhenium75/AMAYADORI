#pragma once
#include "SceneDeclaration.hpp"

struct Title : MyApp::Scene {

	int frameCount = 0;
	int select = 0;
	double stringspace[3] = {0,0,0};
	String string[3] = {L"STORY",L"ARENA",L"EXIT"};
	Font font;
	Font selectfont;

	void init() override {
		font = Font(30, Typeface::Heavy, FontStyle::Outline);
		font.changeOutlineStyle(TextOutlineStyle(Palette::Gray, Palette::Ghostwhite, 2.0));
		selectfont = Font(30, Typeface::Heavy, FontStyle::Outline);
		selectfont.changeOutlineStyle(TextOutlineStyle(Palette::Lightgreen, Palette::Ghostwhite, 2.0));
		SoundAsset(L"titlebgm").setLoop(true);
		SoundAsset(L"titlebgm").play();
		Cursor::SetStyle(CursorStyle::Default);
	}

	void update() override {
		frameCount++;
		FOR(i, 3)
			if (select == i)
				stringspace[i] += (30 - stringspace[i]) / 5;
			else
				stringspace[i] += -stringspace[i] / 5;
		//if (Input::KeyW.clicked) select = (select+2) % 3;
		//if (Input::KeyS.clicked) select = (select + 1) % 3;
		if (Input::KeyW.clicked || Input::KeyS.clicked || Input::KeyUp.clicked || Input::KeyDown.clicked) {
			if (select == 0) select = 2;
			else if (select == 2) select = 0;
			SoundAsset(L"selectcursor").playMulti();
		}
		bool mouse_0 = font(string[0]).region(450, 300).mouseOver;
		bool mouse_1 = font(string[2]).region(450, 400).mouseOver;
		if (mouse_0 && select != 0) {
			select = 0;
			SoundAsset(L"selectcursor").playMulti();
		}
		if (mouse_1 && select != 2){
			select = 2;
			SoundAsset(L"selectcursor").playMulti();
		}
		if (Input::KeyEnter.clicked || (Input::MouseL.clicked &&(mouse_0 || mouse_1)) || Input::KeySpace.clicked) {
			SoundAsset(L"selectenter").playMulti(); 
			if (select == 0) changeScene(L"Select");
			if (select == 2) System::Exit();
		}
	}

	void draw()const override {
		TextureAsset(L"stage").rotate(-frameCount / 300.).drawAt(500, 100);
		TextureAsset(L"title").resize(308,480).draw(0,0);
		FOR(i,3)
			if(select == i)
				selectfont(string[i]).draw(450-stringspace[i],300+i*50);
			else
				font(string[i]).draw(450 - stringspace[i], 300+50*i);
		Line(445, 383, 600, 383).draw(10, {100,100,100,255});
	}

};