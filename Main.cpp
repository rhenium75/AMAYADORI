# include <Siv3D.hpp>
# include "./AMAYADORI/AMAYADORI.hpp"
# include "Actor/DataLoad.hpp"
# include "./Actor/Korone/Korone.hpp"

void Main(){
	TextureAsset::Register(L"korone", L"Data/korone.png");
	TextureAsset::Register(L"sword", L"Data/sword.png");
	GameManager *GM = new GameManager();
	//for (int i = 0; i < 10; i++) {
		//auto flm = new Flm::Flm();
		GM->AddBoss(new Korone::Korone(Group(0)));
	//}
	while (System::Update()){
		GM->Update();
		GM->Draw();
	}
}