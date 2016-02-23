#pragma once
#include <Siv3D.hpp>

class Body {
public:
	Vec2* Pos;
	double Length = 50;
	Vec2 Size;
	int Type = 0;
	Body();
	Body SetType(int);
	Body SetPos(Vec2*);
	Body SetLength(double);
	Body SetSize(Vec2);
	void intersects(Body);
};