# include "./Arena/AMAYADORI_Arena.hpp"

void Main(){
	
	Arena::Setup();

	Arena::GM->AddBoss(new Korone::Korone(Group(0)));
	double r = 0;
	while (System::Update()){
		r += 0.01;
		TextureAsset(L"stage").rotate(r).drawAt(0,0);
		Arena::GM->Update();
		Arena::GM->Draw();
	}
}