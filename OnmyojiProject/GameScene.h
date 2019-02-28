#pragma once
#include "Player.h"
#include "StageInpoter.h"
#include "StageDraw.h"
#include "StageCollision.h"
#include <memory>

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
	std::unique_ptr<StageDraw> stageDraw = std::make_unique<StageDraw>();
	std::unique_ptr<Player> player = std::make_unique<Player>();
	std::unique_ptr<StageCollision> stageCollision = std::make_unique<StageCollision>();

	// �X�e�[�W����
	const int MaxStageNum = StageInpoter::Instance()->GetStageCount();

	vector<position> testVec;

	// GameScene�ōĐ�����X�e�[�W�̔ԍ�
	int stageNum;


	//===============================
	// �֐�
	//===============================

	void Draw();

public:

	void SetStageNum(int num);

	void Update();
};