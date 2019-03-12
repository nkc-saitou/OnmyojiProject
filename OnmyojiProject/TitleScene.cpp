#include "TitleScene.h"
#include "DxLib.h"
#include "Input.h"
#include "E_SceneState.h"
#include "ImageLoader.h"


void TitleScene::Draw()
{
	DrawGraph(0, 0, ImageLoader::Instance()->GetBackTitleGroundGh(), TRUE);
	DrawGraph(screenX, screenY, ImageLoader::Instance()->GetTitleLogoGh(), TRUE);
}

void TitleScene::Uptate()
{
	Draw();

	if (Input::Instance()->ButtonDown(XINPUT_BUTTON_A, Pad_1) || Input::Instance()->ButtonDown(KEY_INPUT_RETURN))
	{
		SettingProvider::Instance()->SetSceneState(SceneState::gameScene);
	}

}