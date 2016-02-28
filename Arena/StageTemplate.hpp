#pragma once
#include "Declaration.hpp"

class StageStory : public Stage {
public:
	Player* player;
	Actor* boss;
	StageStory();
};