#pragma once
#include "StageTemplate.hpp"
#include "Garnet.hpp"
#include "Korone.hpp"
class StageGarnet : public StageStory {
public:
	Team* PlayerTeam;
	Team* EnemyTeam;
	BigCamera camera;
	StageGarnet();
	void Update()override;
	void Draw()const override;
};