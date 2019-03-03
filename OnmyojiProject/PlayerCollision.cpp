#include "PlayerCollision.h"
#include "SettingProvider.h"
#include "Collision.h"

/////////////////////////////////////////////////////
//����			:�v���C���[�Ɠ��������I�u�W�F�N�g�͈̔͂��󂯎�肽��Rect
//�߂�l		:�v���C���[���������Ă�����true
//����			:�v���C���[�Ɠ������Ă��邩�ǂ����𒲂ׂ�
/////////////////////////////////////////////////////
bool PlayerCollision::OnCollision(Rect& collisionRect)
{
	if (stageCollision->OnCollision(playerRect,collisionRect)) return true;
	else return false;
}

bool PlayerCollision::AnyCollision(Rect playerRect, Rect& targetRect)
{
	if (Collision::Instance()->CheckRectAndRect(playerRect, targetRect))
	{
		targetRect = playerRect;
		return true;
	}
}

/////////////////////////////////////////////////////
//����			:�v���C���[�̓����蔻��
//�߂�l		:�Ȃ�
//����			:�v���C���[�̓����蔻��͈̔͂�ݒ肷��
/////////////////////////////////////////////////////
void PlayerCollision::SetPlayerRect(Rect targetRect)
{
	playerRect = targetRect;
}

/////////////////////////////////////////////////////
//����			:�I�������X�e�[�W�ԍ�
//�߂�l		:�Ȃ�
//����			:�ǂ̓����蔻���ݒ肷��
/////////////////////////////////////////////////////
void PlayerCollision::SetRockRect(int stageNum)
{
	stageCollision->SetCollsionPosition(StageInpoter::Instance()->GetCollisionData()[SettingProvider::Instance()->GetStageNumber()]);
}

