#pragma once

#include "StageCollision.h"
#include "StageInpoter.h"

using namespace std;

/*
///////////////////////////////////////////
PlayerCollision�N���X

�T�v�@�F�v���C���[�̓����蔻��̊Ǘ�
///////////////////////////////////////////
*/
class PlayerCollision
{
	unique_ptr<StageCollision> stageCollision = make_unique<StageCollision>();

	Rect playerRect;

public:

	// �����ɂ����������ǂ���
	bool OnCollision(Rect& collisionRect);

	// ��̓����蔻����Z�b�g
	void SetRockRect(int stageNum);

	// �v���C���[�̓����蔻����Z�b�g
	void SetPlayerRect(Rect targetRect);

};