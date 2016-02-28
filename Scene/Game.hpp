#pragma once
#include "SceneDeclaration.hpp"

struct Game : MyApp::Scene {

	int frameCount = 0;
	Stage* stage;
	Font font;
	bool stop = false;

	void init() override {
		stage = new StageKinako();
		font = Font(10);
		Cursor::SetStyle(CursorStyle::None);
	}

	void update() override {
		stage->Update();
		frameCount++;
	}

	void draw()const override {
		stage->Draw();
		//Println(L"FrameRate:"+Format(Profiler::FPS()));
		Graphics2D::SetTransform(Mat3x2::Translate(Vec2(0, 0)));
		if (frameCount < 120)
			TextureAsset(L"gamestart").drawAt(320,240,Alpha(255*(120-frameCount)/120.));
		font.draw(L"FrameRate:" + Format(Profiler::FPS()));
	}

};