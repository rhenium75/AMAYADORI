#include "../Body.hpp"

Body::Body() {
}

Body Body::SetType(int type) {
	Type = type;
	return *this;
}

Body Body::SetPos(Vec2* pos) {
	Pos = pos;
	return *this;
}

Body Body::SetLength(double length) {
	Length = length;
	return *this;
}

Body Body::SetSize(Vec2 size) {
	Size = size;
	return *this;
}

void Body::intersects(Body body) {
	if (Pos->distanceFrom(*body.Pos) < body.Length+Length) {
		Vec2 dee = (*Pos - *body.Pos) / 2;
		*Pos +=  dee;
		*body.Pos -= dee;
	}
}
