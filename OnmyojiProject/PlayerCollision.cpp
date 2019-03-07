#include "PlayerCollision.h"
#include "CollisionRectProvider.h"
#include <vector>

namespace PlayerScope
{
	/////////////////////////////////////////////////////
	//����			:�v���C���[�Ɠ��������I�u�W�F�N�g�͈̔͂��󂯎�肽��Rect
	//�߂�l		:�v���C���[���������Ă�����true
	//����			:�v���C���[�Ɠ������Ă��邩�ǂ����𒲂ׂ�
	/////////////////////////////////////////////////////
	bool PlayerCollision::OnCollision(int x, int y)
	{
		Rect playerRect = CollisionRectProvider::Instance()->GetPlayerRect();
		std::vector<Rect> rockRect = CollisionRectProvider::Instance()->GetRockRect();
		std::vector<Rect> stageRect = CollisionRectProvider::Instance()->GetStageRect();

		// �T�C�Y���擾
		int rockRectCount = rockRect.size();
		int stageRectCount = stageRect.size();

		// �X�e�[�W��̕ǂƓ������Ă��邩�ǂ���
		for (int i = 0; i < stageRectCount; i++)
		{
			if (objectCollision->OnCollision(playerRect, stageRect[i])) return true;
		}

		// �������A��ʊO�ɏo�Ȃ��悤��
		if (x + graphSize * 2 > screenSizeX) return true;
		if (x < graphSize) return true;

		// �������A��ʊO�ɏo�Ȃ��悤��
		if (y + graphSize * 2 > screenSizeY) return true;
		if (y < graphSize) return true;

		return false;
	}
}

