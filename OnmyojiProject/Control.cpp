#include "Control.h"
#include "DxLib.h"

Control::Control()
{
	ImageLoader::Instance()->ImageDiv();
	gameScene->SetStageNum(1);
}

void Control::SceneChange(SceneState scene)
{
	
}

void Control::Update()
{
	gameScene->Update();
}