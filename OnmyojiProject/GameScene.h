#pragma once
#include "Player.h"
#include "StageInpoter.h"
#include "StageDraw.h"
#include <memory>

class GameScene
{
	std::unique_ptr<StageDraw> stageDraw = std::make_unique<StageDraw>();
	std::unique_ptr<Player> player = std::make_unique<Player>();

	const int MaxStageNum = StageInpoter::Instance()->StageCount();

	int stageNum;


	void Draw();

public:

	GameScene(int num);

	void Update();
};