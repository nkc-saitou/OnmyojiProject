#include "Control.h"
#include "DxLib.h"

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:画像の読み込み
/////////////////////////////////////////////////////
Control::Control()
{
	ImageLoader::Instance()->ImageDiv();

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
		titleScene->Uptate();
		break;

	case SceneState::selectScene:
		break;

	case SceneState::gameScene:
		if (isSceneChange(memoryState, sceneState)) gameScene->SetStage(0);
		gameScene->Update();
		break;

	case SceneState::resultScene:
		if (isSceneChange(memoryState, sceneState)) resultScene->Init();
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