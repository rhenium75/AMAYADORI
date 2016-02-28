#include "../Body.hpp"

Body::Body() {
	Pos.set(0, 0);
	Force.set(0,0);
}


Body* Body::SetPos(Vec2 pos) {
	Pos = pos;
	return this;
}

Body* Body::SetForce(Vec2 force) {
	Force = force;
	return this;
}

Body* Body::SetAnagle(double angle) {
	Angle = angle;
	return this;
}

Body* Body::SetLength(double length) {
	Length = length;
	return this;
}

Body * Body::SetAirResistance(double air) {
	AirResistance = air;
	return this;
}

void Body::AddPos(Vec2 pos) {
	Pos += pos;
}

void Body::AddAngle(double angle) {
	Angle += angle;
}

void Body::Update() {
	Pos += Force;
	Force -= Force*AirResistance;
}

void Body::AddForce(Vec2 force) {
	Force += force;
}

Vec2 Body::GetPos()const{
	return Pos;
}

Vec2 Body::GetForce()const{
	return Force;
}

double Body::GetAngle()const{
	return Angle;
}

bool Body::Hit(Body body)const{
	return Circle(Pos).setSize(Length).intersects(Circle(body.Pos).setSize(body.Length));
}

void Body::intersects(Body body) {
	if (Pos.distanceFrom(body.Pos) < body.Length+Length) {
		Vec2 dee = (Pos - body.Pos) / 2;
		//AddPos(dee);
		//body.AddPos(-dee);
		AddForce(dee/3);
		body.AddForce(-dee/3);
	}
}
