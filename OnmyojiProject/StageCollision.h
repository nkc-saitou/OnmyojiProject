#pragma once

#include <vector>
#include "StageInpoter.h"
#include "RectShape.h"

using namespace std;

/*
///////////////////////////////////////////
StageCollision�N���X

�T�v�@�F�X�e�[�W�ɐݒu����Ă��铮���Ȃ��ǂ̓����蔻��̊Ǘ�
///////////////////////////////////////////
*/
class StageCollision
{
	vector<position> collisionPos;

	vector<Rect> collisionRange;

    const int graphSize = 64;

	// �����蔻��͈̔͂�ݒ�
	void CollisionRangeSet();
public:

	// �I�����ꂽ�X�e�[�W�̓����蔻������擾
	void SetCollsionPosition();
};