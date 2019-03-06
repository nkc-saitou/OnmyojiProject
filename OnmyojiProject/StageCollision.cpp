#include "StageCollision.h"
#include "Collision.h"
#include "CollisionRectProvider.h"
#include "SettingProvider.h"

#include "DxLib.h"

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�����蔻��͈̔͂�ݒ�
/////////////////////////////////////////////////////
void StageCollision::CollisionRangeSet()
{
	const int offset = 5;
	for (int i = 0; i < collisionPos.size(); i++)
	{
		Rect tempRect;

		// �����蔻��̈ʒu��Z�ʂ�����
		tempRect.top = collisionPos[i].y * graphSize + offset;
		tempRect.left = collisionPos[i].x * graphSize + offset;
		tempRect.bottom = tempRect.top + graphSize - offset;
		tempRect.right = tempRect.left + graphSize - offset * 2;

		collisionRange.push_back(tempRect);
	}
	CollisionRectProvider::Instance()->SetStageRect(collisionRange);
}

/////////////////////////////////////////////////////
//����			:�I�����ꂽ�X�e�[�W�̕ǂ̍��W
//�߂�l		:�Ȃ�
//����			:�I�����ꂽ�X�e�[�W�̓����蔻����Z�b�g����
/////////////////////////////////////////////////////
void StageCollision::SetCollsionPosition()
{
	int stageNum = SettingProvider::Instance()->GetStageNumber();
	vector<position> poss = StageInpoter::Instance()->GetStageCollisionData()[stageNum];

	collisionPos = poss;
	CollisionRangeSet();
}