#pragma once
#include "SceneDeclaration.hpp"

struct Select : MyApp::Scene {

	Font font;
	void init() override {
		font = Font(30, Typeface::Heavy, FontStyle::Outline);
		font.changeOutlineStyle(TextOutlineStyle(Palette::Green, Palette::Orange, 2.0));
	}

	void update() override {
		if (Input::MouseL.clicked || Input::KeyEnter.clicked || Input::KeySpace.clicked) {
			SoundAsset(L"titlebgm").stop();
			SoundAsset(L"selectenter").playMulti();
			changeScene(L"Game");
		}
	}

	void draw()const override {
		Rect(640,480).draw(Palette::White);
		TextureAsset(L"koroneselect").draw(0,0);
		font(L"ÉRÉçÉl").draw(450,100);
	}

};