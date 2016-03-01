#pragma once

class Stage {
public:
	int gameendframe;
	bool win;
	Stage();
	virtual void Update();
	virtual void Draw()const = 0;
	virtual void Exit();
};
