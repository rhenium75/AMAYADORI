#pragma once
#include "Declaration.hpp"

class StageStory : public Stage {
public:
	Actor* player;
	Actor* boss;
	StageStory();
};