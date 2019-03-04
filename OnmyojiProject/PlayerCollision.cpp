#include "PlayerCollision.h"
#include "RectWatcher.h"
#include <vector>


/////////////////////////////////////////////////////
//����			:�v���C���[�Ɠ��������I�u�W�F�N�g�͈̔͂��󂯎�肽��Rect
//�߂�l		:�v���C���[���������Ă�����true
//����			:�v���C���[�Ɠ������Ă��邩�ǂ����𒲂ׂ�
/////////////////////////////////////////////////////
bool PlayerCollision::OnCollision(Rect& collisionRect)
{
	Rect playerRect = RectWatcher::Instance()->GetPlayerRect();
	vector<Rect> rockRect = RectWatcher::Instance()->GetRockRect();
	vector<Rect> stageRect = RectWatcher::Instance()->GetStageRect();

	// for���Ŕ�΂�
	if (objectCollision->OnCollision(playerRect,collisionRect)) return true;
	else return false;
}

