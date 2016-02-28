#pragma once
#include "SceneDeclaration.hpp"

struct Result : MyApp::Scene {

	void init() override {
	}

	void update() override {
		if (Input::MouseL.clicked)
			changeScene(L"Title");
	}

	void draw()const override {
	}

};