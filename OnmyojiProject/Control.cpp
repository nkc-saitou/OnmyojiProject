#include "Control.h"
#include "DxLib.h"
#include "AudioManager.h"
#include "Input.h"
#include "FadeManager.h"

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:画像の読み込み
/////////////////////////////////////////////////////
Control::Control()
{
	ImageLoader::Instance()->ImageDiv();
	AudioManager::Instance()->LoadSound();

	AudioManager::Instance()->PlayBGM(AudioManager::Instance()->GetBGM_TitleSH());

	FadeManager::Instance()->ResetFadeValue();
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:画像の読み込み
/////////////////////////////////////////////////////
void Control::ChangeScene()
{
	sceneState = SettingProvider::Instance()->GetSceneState();

	// シーン遷移したかどうか
	auto isSceneChange = [](SceneState memoryState, SceneState sceneState)
	{
		return (memoryState != sceneState) ? true : false;
	};

	switch (sceneState)
	{
	case SceneState::titleScene:
		// 前フレームと比較して、シーンが変わっていたら
		if (isSceneChange(memoryState, sceneState))
		{
			AudioManager::Instance()->PlayBGM(AudioManager::Instance()->GetBGM_TitleSH());
		}

		titleScene->Uptate();
		break;

	case SceneState::selectScene:
		break;

	case SceneState::gameScene:
		if (isSceneChange(memoryState, sceneState))
		{
			AudioManager::Instance()->PlayBGM(AudioManager::Instance()->GetBGM_GameSh());
			// ステージ読み込み
			gameScene->SetStage(0);
		}

		gameScene->Update();
		break;

	case SceneState::resultScene:
		if (isSceneChange(memoryState, sceneState))
		{
			AudioManager::Instance()->PlayBGM(AudioManager::Instance()->GetBGM_ResultSh());
			resultScene->Init();
		}
		resultScene->Update();
		break;
	}

	// 更新
	memoryState = sceneState;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:更新
/////////////////////////////////////////////////////
void Control::Update()
{
	ChangeScene();
}