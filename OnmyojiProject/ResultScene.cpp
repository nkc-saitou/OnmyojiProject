#include "ResultScene.h"
#include "StageInpoter.h"
#include "FadeManager.h"
#include "ImageLoader.h"
#include "Input.h"

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:初期化
/////////////////////////////////////////////////////
void ResultScene::Init()
{
	stageDraw = make_unique<StageDraw>(SceneState::resultScene);

	stageNum = SettingProvider::Instance()->GetStageNumber();

	stageDraw->SetStageData(StageInpoter::Instance()->GetStageData()[stageNum]);

	isFadeFirst = false;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:描画
/////////////////////////////////////////////////////
void ResultScene::Draw()
{
	stageDraw->Update();
	DrawGraph(SettingProvider::Instance()->screenSizeX / 3.5, SettingProvider::Instance()->screenSizeY / 2.5, ImageLoader::Instance()->GetClearLogoGh(), TRUE);
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:更新
/////////////////////////////////////////////////////
void ResultScene::Update()
{
	Draw();

	if (isFadeFirst == false)
		if (FadeManager::Instance()->IsWhiteFadeOut()) isFadeFirst = true;

	// フェード中はシーン遷移しない
	if (isFadeFirst != true) return;

	if (Input::Instance()->ButtonDown(XINPUT_BUTTON_A, Pad_1) || Input::Instance()->ButtonDown(KEY_INPUT_RETURN))
	{
		SettingProvider::Instance()->SetSceneState(SceneState::titleScene);
	}

}