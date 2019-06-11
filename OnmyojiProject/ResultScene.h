#pragma once
#include "SettingProvider.h"
#include "StageDraw.h"

/*
///////////////////////////////////////////
ResultSceneクラス

概要　：リザルト画面制御クラス
///////////////////////////////////////////
*/
class ResultScene
{
	std::unique_ptr<StageDraw> stageDraw;
	bool isFadeFirst = false;

	int stageNum;

	void Draw();

public:
	void Init();

	void Update();
};