# include "Scene/Scene.hpp"
# include "./Arena/Arena.hpp"

void Main(){
	Arena_Setup();

	Window::SetTitle(L"AMAYADORI BETA");
	Window::Resize({ 640,480 });
	MyApp manager;
	manager.setFadeColor(Palette::Black);
	manager.add<Title>(L"Title");
	manager.add<Game>(L"Game");
	manager.add<Select>(L"Select");
	manager.init(L"Title");

	while (System::Update()){
		if (!manager.updateAndDraw()) break;
	}
}