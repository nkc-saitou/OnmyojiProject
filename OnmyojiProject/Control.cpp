#include "Control.h"
#include "DxLib.h"

Control::Control()
{
	ImageLoader::Instance()->ImageDiv();
}

void Control::SceneChange(SceneState scene)
{

}

void Control::Update()
{
	gameScene->Update();
}