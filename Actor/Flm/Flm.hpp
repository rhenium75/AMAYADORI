#pragma once
# include "../../AMAYADORI/AMAYADORI.hpp"

class Flm : public Actor {
public:
	int num;
	Flm(int _num) {
		hp = 1;
		num = _num;
	}
	void Update()override{
		Println(num);
	}
	void Draw()const override {

	}
};