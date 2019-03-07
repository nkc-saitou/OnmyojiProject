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
GameScene�N���X

�T�v�@�F�Q�[���V�[�����Ǘ�����N���X
///////////////////////////////////////////
*/
class GameScene
{
	//===============================
	// �ϐ�
	//===============================
	// �X�e�[�W����
	const int MaxStageNum = StageInpoter::Instance()->GetStageCount();

	std::unique_ptr<StageDraw> stageDraw = std::make_unique<StageDraw>();
	std::unique_ptr<PlayerScope::Player> player = std::make_unique<PlayerScope::Player>();
	std::unique_ptr<StageCollision> stageCollision = std::make_unique<StageCollision>();
	std::unique_ptr<RockScope::RockController> rockController = std::make_unique<RockScope::RockController>();
	std::unique_ptr<CreateGoalPoint> createGoalPoint = std::make_unique<CreateGoalPoint>();

	vector<Rect> testVec;

	// GameScene�ōĐ�����X�e�[�W�̔ԍ�
	int stageNum;


	//===============================
	// �֐�
	//===============================

	void Draw();

public:

	void SetStage(int num);

	void Update();
};