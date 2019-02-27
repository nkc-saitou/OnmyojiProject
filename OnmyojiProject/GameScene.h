#pragma once
#include "Player.h"
#include "StageInpoter.h"
#include "StageDraw.h"
#include <memory>

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
	std::unique_ptr<StageDraw> stageDraw = std::make_unique<StageDraw>();
	std::unique_ptr<Player> player = std::make_unique<Player>();

	// ステージ総数
	const int MaxStageNum = StageInpoter::Instance()->GetStageCount();

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