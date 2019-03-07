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

	std::unique_ptr<StageDraw> stageDraw = std::make_unique<StageDraw>();
	std::unique_ptr<PlayerScope::Player> player = std::make_unique<PlayerScope::Player>();
	std::unique_ptr<StageCollision> stageCollision = std::make_unique<StageCollision>();
	std::unique_ptr<RockScope::RockController> rockController = std::make_unique<RockScope::RockController>();
	std::unique_ptr<CreateGoalPoint> createGoalPoint = std::make_unique<CreateGoalPoint>();

	vector<Rect> testVec;

	// GameSceneで再生するステージの番号
	int stageNum;


	//===============================
	// 関数
	//===============================

	void Draw();

public:

	void SetStage(int num);

	void Update();
};