#pragma once

class Actor {
public:
	Vec2 Pos;
	int hp;
	void Update();
	void Draw()const;
	bool IsDeath();
};