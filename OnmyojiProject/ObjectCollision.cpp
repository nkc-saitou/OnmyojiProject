#include "ObjectCollision.h"
#include "Collision.h"


/////////////////////////////////////////////////////
//����			:�v���C���[�Ɠ��������I�u�W�F�N�g�͈̔͂��󂯎�肽��Rect
//�߂�l		:�v���C���[���������Ă�����true
//����			:�v���C���[�Ɠ������Ă��邩�ǂ����𒲂ׂ�
/////////////////////////////////////////////////////
bool ObjectCollision::OnCollision(Rect myRect, Rect opponentRect)
{
	if (Collision::Instance()->CheckRectAndRect(myRect, opponentRect))
	{
		return true;
	}
	return false;
}