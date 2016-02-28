#pragma once

class Stage {
public:
	Stage();
	virtual void Update();
	virtual void Draw()const = 0;
	virtual void Exit();
};
