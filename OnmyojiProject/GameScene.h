#pragma once

#include <memory>

#include "Player.h"
#include "StageInpoter.h"
#include "StageDraw.h"
#include "StageCollision.h"
#include "Rock.h"



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
	std::unique_ptr<Player> player = std::make_unique<Player>();
	std::unique_ptr<StageCollision> stageCollision = std::make_unique<StageCollision>();

	vector<unique_ptr<Rock>> rock;

	vector<position> testVec;

	// GameSceneで再生するステージの番号
	int stageNum;


	//===============================
	// 関数
	//===============================

	void Draw();

public:

	void SetStageNum(int num);

	void Update();
};