#include "ResultScene.h"
#include "StageInpoter.h"
#include "FadeManager.h"
#include "Input.h"

void ResultScene::Init()
{
	stageDraw = make_unique<StageDraw>(SceneState::resultScene);

	stageNum = SettingProvider::Instance()->GetStageNumber();

	stageDraw->SetStageData(StageInpoter::Instance()->GetStageData()[stageNum]);

	isFadeFirst = false;
}

void ResultScene::Draw()
{
	stageDraw->Update();
}

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