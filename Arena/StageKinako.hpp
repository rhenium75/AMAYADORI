#pragma once
#include "Declaration.hpp"
#include "StageTemplate.hpp"
#include "Korone.hpp"
#include "Kinako.hpp"

class StageKinako : public StageStory {
public:
	Team* PlayerTeam;
	Team* EnemyTeam;
	BigCamera camera;
	StageKinako();
	void Update()override;
	void Draw()const override;
	void Exit()override;
};