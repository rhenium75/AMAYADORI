# include "./Arena/Arena.hpp"

void Main(){
	
	Arena_Setup();
	Stage* stage = new StageGarnet();

	const Font font(30);
	while (System::Update()){
	
		stage->Update();
		stage->Draw();
		//Println(L"FrameRate:"+Format(Profiler::FPS()));
		font.draw(L"FrameRate:" + Format(Profiler::FPS()));
	}
}