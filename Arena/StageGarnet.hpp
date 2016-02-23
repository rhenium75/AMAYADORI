#pragma once
#include "StageTemplate.hpp"
#include "Garnet.hpp"
#include "Korone.hpp"
class StageGarnet : public StageStory {
public:
	StageGarnet();
	void Update()override;
	void Draw()const override;
};