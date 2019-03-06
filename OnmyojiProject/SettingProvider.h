#pragma once

#include "Singleton.h"

/*
///////////////////////////////////////////
SettingProviderクラス

概要　：ゲーム共通の情報(スクリーンサイズなど)が取得できるクラス
///////////////////////////////////////////
*/
class SettingProvider : public Singleton <SettingProvider>
{
	int stageNumber;

public:
	const int screenSizeX = 1920;
	const int screenSizeY = 1080;

	void SetStageNumber(int stageNum) { stageNumber = stageNum; }
	int GetStageNumber() { return stageNumber; }
};