#pragma once

#include "StageInpoter.h"
#include "ObjectCollision.h"

using namespace std;

// ���ݎQ�Ƃ̂��ߑO���錾
class RockCollision;
/*
///////////////////////////////////////////
PlayerCollision�N���X

�T�v�@�F�v���C���[�̓����蔻��̊Ǘ�
///////////////////////////////////////////
*/
class PlayerCollision
{
	unique_ptr<ObjectCollision> objectCollision = make_unique<ObjectCollision>();



public:


	// �����ɂ����������ǂ���
	bool OnCollision(Rect& collisionRect);

};