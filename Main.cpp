#pragma once
# include <Siv3D.hpp>
# include "./AMAYADORI/AMAYADORI.cpp"

void Main(){
	GM = new GameManager();
	while (System::Update()){
		GM->Update();
		GM->Draw();
	}
}
