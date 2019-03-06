#include "Control.h"
#include "DxLib.h"

Control::Control()
{
	ImageLoader::Instance()->ImageDiv();
	gameScene->SetStage(0);
}

void Control::SceneChange(SceneState scene)
{
	
}

void Control::Update()
{
	gameScene->Update();
}