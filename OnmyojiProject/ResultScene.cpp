#include "ResultScene.h"
#include "StageInpoter.h"
#include "FadeManager.h"
#include "Input.h"

void ResultScene::Init()
{
	stageDraw = make_unique<StageDraw>(SceneState::resultScene);

	stageNum = SettingProvider::Instance()->GetStageNumber();

	stageDraw->SetStageData(StageInpoter::Instance()->GetStageData()[stageNum]);
}

void ResultScene::Draw()
{
	stageDraw->Update();
}

void ResultScene::Update()
{
	Draw();

	if (isFadeFirst == false)
		if(FadeManager::Instance()->IsWhiteFadeOut()) isFadeFirst = true;

	if (Input::Instance()->ButtonDown(XINPUT_BUTTON_A, Pad_1))
	{
		SettingProvider::Instance()->SetSceneState(SceneState::titleScene);
	}
}