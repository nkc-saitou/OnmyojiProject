#include "StageCollision.h"
#include "Collision.h"

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
}

/////////////////////////////////////////////////////
//����			:�����蔻��𒲂ׂ����I�u�W�F�N�g��Rect , ���������I�u�W�F�N�g��Rect
//�߂�l		:�������Ă�����true
//����			:�����ŗ^�����I�u�W�F�N�g�ƁA�����Ȃ��ǂ��������Ă��邩�ǂ����𒲂ׂ�B
//               �������Ă����ꍇ�́A���������ǂ�Rect��n��
/////////////////////////////////////////////////////
bool StageCollision::OnCollision(Rect playerRect, Rect& collisionRect)
{
	for (int i = 0; i < collisionRange.size(); i++)
	{
		if (Collision::Instance()->CheckRectAndRect(playerRect, collisionRange[i]))
		{
			collisionRect = collisionRange[i];
			return true;
		}
	}

	return false;
}

/////////////////////////////////////////////////////
//����			:�I�����ꂽ�X�e�[�W�̕ǂ̍��W
//�߂�l		:�Ȃ�
//����			:�I�����ꂽ�X�e�[�W�̓����蔻����Z�b�g����
/////////////////////////////////////////////////////
void StageCollision::SetCollsionPosition(vector<position> pos)
{
	collisionPos = pos;
	CollisionRangeSet();
}