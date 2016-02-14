#pragma once
#include "../../AMAYADORI/Src/Actor.cpp"

class Flm : public Actor {
public:
	void init() {
		hp = 1;
	}
	void Update()override{
		Print(L"Test");
	}
	void Draw()const override {

	}
};