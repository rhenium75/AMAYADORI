#pragma once
#include <Siv3D.hpp>

class Body {
private:
	Vec2 Pos;
	double Length = 1;
	double Angle = 0;
	Vec2 Force;
	double AirResistance = 0.1;
public:
	Body();
	Body* SetPos(Vec2);
	Body* SetForce(Vec2);
	Body* SetAnagle(double);
	Body* SetLength(double);
	Body* SetAirResistance(double);

	void AddPos(Vec2);
	void AddAngle(double);

	void Update();

	void AddForce(Vec2);

	Vec2 GetPos()const;
	Vec2 GetForce()const;
	double GetAngle()const;

	bool Hit(Body)const;
	void intersects(Body);
};