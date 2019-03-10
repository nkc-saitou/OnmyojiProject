#pragma once

#include "Singleton.h"
#include "E_SceneState.h"

/*
///////////////////////////////////////////
SettingProviderクラス

概要　：ゲーム共通の情報(スクリーンサイズなど)が取得できるクラス
///////////////////////////////////////////
*/
class SettingProvider : public Singleton <SettingProvider>
{
	int stageNumber;

	bool isClear = false;

	SceneState sceneState = SceneState::titleScene;


public:
	const int screenSizeX = 1920;
	const int screenSizeY = 1080;

	void SetSceneState(SceneState scene) { sceneState = scene; }
	SceneState GetSceneState() { return sceneState; }

	void SetStageNumber(int stageNum) { stageNumber = stageNum; }
	int GetStageNumber() { return stageNumber; }

	void SetClearFlg(bool clearFlg) { isClear = clearFlg; }
	bool GetIsClear() { return isClear; }
};