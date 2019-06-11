#pragma once
#include "SettingProvider.h"
#include "StageDraw.h"

/*
///////////////////////////////////////////
ResultScene�N���X

�T�v�@�F���U���g��ʐ���N���X
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