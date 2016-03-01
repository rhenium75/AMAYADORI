#pragma once
#include "SceneDeclaration.hpp"

struct Game : MyApp::Scene {

	int frameCount = 0;
	Stage* stage;
	Font font;
	Font frameRateFont;
	bool stop = false;

	void init() override {
		stage = new StageKinako();
		Cursor::SetStyle(CursorStyle::None);
		System::SetExitEvent(EXIT_FAILURE);

		frameRateFont = Font(10, Typeface::Heavy, FontStyle::Outline);
		frameRateFont.changeOutlineStyle(TextOutlineStyle(Palette::Gray, Palette::Ghostwhite, 2.0));
		font = Font(30, Typeface::Heavy, FontStyle::Outline);
		font.changeOutlineStyle(TextOutlineStyle(Palette::Gray, Palette::Ghostwhite, 2.0));
	}

	void update() override {
		if (!stop) {
			frameCount++;
			Cursor::SetStyle(CursorStyle::None);
			stage->Update();
			Cursor::SetPos(320, 240);
		}
		else if(stop){
			Cursor::SetStyle(CursorStyle::Default);
			if(Input::KeyQ.clicked)
				System::Exit();
			if (Input::MouseL.clicked) {
				if (Rect(280,145,100,50).mouseOver)
					System::Exit();
				if (Rect(280, 215, 100, 50).mouseOver){
					stage->Exit();
					changeScene(L"Title");
				}
				if (Rect(280, 285, 100, 50).mouseOver)
					stop = false;
			}
		}
		if (Input::KeyEscape.clicked)
			stop = !stop;
		if (stage->gameendframe == 1) {
			stage->Exit();
			changeScene(L"Title");
		}
	}

	void draw()const override {
		stage->Draw();
		//Println(L"FrameRate:"+Format(Profiler::FPS()));
		Graphics2D::SetTransform(Mat3x2::Translate(Vec2(0, 0)));
		if (frameCount < 120)
			TextureAsset(L"gamestart").drawAt(320,240,Alpha(255*(120-frameCount)/120.));
		font.draw(L"FrameRate:" + Format(Profiler::FPS()));
		if (stop) {
			Rect(640, 480).draw({100,100,100,50});
			font(L"EXIT").drawCenter(320,145);
			font(L"TITLE").drawCenter(320, 215);
			font(L"CLOSE").drawCenter(320, 285);
		}
	}

};