#pragma once
# include <Siv3D.hpp>
# include "./AMAYADORI/AMAYADORI.hpp"
# include "./Actor/Flm/Flm.hpp"

void Main(){
	GameManager *GM = new GameManager();
	GM->AddBoss(new Flm());
	while (System::Update()){
		GM->Update();
		GM->Draw();
	}
}