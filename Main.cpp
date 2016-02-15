# include <Siv3D.hpp>
# include "./AMAYADORI/AMAYADORI.hpp"
# include "./Actor/Flm/Flm.hpp"

void Main(){
	GameManager *GM = new GameManager();
	for (int i = 0; i < 10; i++) {
		auto flm = new Flm(100);
		GM->AddBoss(flm);
	}
	while (System::Update()){
		GM->Update();
		GM->Draw();
	}
}