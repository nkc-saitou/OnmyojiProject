#pragma once

#include <memory>

#include "Player.h"
#include "StageInpoter.h"
#include "StageDraw.h"
#include "StageCollision.h"
#include "RockController.h"
#include "CreateGoalPoint.h"

/*
///////////////////////////////////////////
GameSceneクラス

概要　：ゲームシーンを管理するクラス
///////////////////////////////////////////
*/
class GameScene
{
	//===============================
	// 変数
	//===============================
	// ステージ総数
	const int MaxStageNum = StageInpoter::Instance()->GetStageCount();

	std::unique_ptr<StageDraw> stageDraw;
	std::unique_ptr<PlayerScope::Player> player;
	std::unique_ptr<StageCollision> stageCollision;
	std::unique_ptr<RockScope::RockController> rockController;
	std::unique_ptr<CreateGoalPoint> createGoalPoint;

	vector<Rect> testVec;

	// GameSceneで再生するステージの番号
	int stageNum;


	//===============================
	// 関数
	//===============================

	void Draw();

	void GameClear();

public:

	void SetStage(int num);

	void Update();
};