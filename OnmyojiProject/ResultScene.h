#pragma once
#include "SettingProvider.h"
#include "StageDraw.h"

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