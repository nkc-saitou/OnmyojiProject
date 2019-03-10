#include "TitleScene.h"
#include "DxLib.h"
#include "Input.h"
#include "E_SceneState.h"
#include "ImageLoader.h"

void TitleScene::Draw()
{
	DrawGraph(screenX, screenY, ImageLoader::Instance()->GetTitleLogoGh(), FALSE);
}

void TitleScene::Uptate()
{
	Draw();

	if (Input::Instance()->ButtonDown(XINPUT_BUTTON_A, Pad_1))
	{
		SettingProvider::Instance()->SetSceneState(SceneState::gameScene);
	}
}