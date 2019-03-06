#include "RockCollision.h"
#include "SettingProvider.h"
#include "CollisionRectProvider.h"


namespace RockScope 
{
	bool RockCollision::OnCollision(Rect myRockRect, int x, int y, Rect& collisionRect, CollisionObjType& type)
	{
		Rect playerRect = CollisionRectProvider::Instance()->GetPlayerRect();
		std::vector<Rect> rockRect = CollisionRectProvider::Instance()->GetRockRect();
		std::vector<Rect> stageRect = CollisionRectProvider::Instance()->GetStageRect();

		Rect topEdgeStageRect = CollisionRectProvider::Instance()->GetRightEdgeStageRect();
		Rect bottomEdgeStageRect = CollisionRectProvider::Instance()->GetLeftEdgeStageRect();
		Rect leftEdgeStageRect = CollisionRectProvider::Instance()->GetBottomEdgeStageRect();
		Rect rightEdgeStageRect = CollisionRectProvider::Instance()->GetTopEdgeStageRect();

		// �T�C�Y���擾
		int rockRectCount = rockRect.size();
		int stageRectCount = stageRect.size();

		if (objectCollision->OnCollision(myRockRect, playerRect))
		{
			type = player;
			return true;
		}

		// �΂Ɠ������Ă��邩�ǂ���
		for (int i = 0; i < rockRectCount; i++)
		{
			// �����Ă���I�u�W�F�N�g(myRockRect������)�ƁA
			// rockRect�z��Ɋ܂܂�Ă���I�u�W�F�N�g(rockRect[i]������)�������������ꍇ�͓����蔻��𒲂ׂȂ�
			if (myRockRect.left == rockRect[i].left && myRockRect.top == rockRect[i].top) continue;

			if (objectCollision->OnCollision(myRockRect, rockRect[i]))
			{
				type = rock;
				collisionRect = rockRect[i];
				return true;
			}
		}

		// �X�e�[�W��̕ǂƓ������Ă��邩�ǂ���
		for (int i = 0; i < stageRectCount; i++)
		{
			if (objectCollision->OnCollision(myRockRect, stageRect[i]))
			{
				type = wall;
				collisionRect = stageRect[i];
				return true;
			}
		}

		// �������A��ʊO�ɏo�Ȃ��悤��
		if (objectCollision->OnCollision(myRockRect, rightEdgeStageRect))
		{
			type = wall;
			collisionRect = rightEdgeStageRect;
			return true;
		}
		if (objectCollision->OnCollision(myRockRect, leftEdgeStageRect))
		{
			type = wall;
			collisionRect = leftEdgeStageRect;
			return true;
		}

		// �������A��ʊO�ɏo�Ȃ��悤��
		if (objectCollision->OnCollision(myRockRect, bottomEdgeStageRect))
		{
			type = wall;
			collisionRect = bottomEdgeStageRect;
			return true;
		}
		if (objectCollision->OnCollision(myRockRect, topEdgeStageRect))
		{
			type = wall;
			collisionRect = topEdgeStageRect;
			return true;
		}

		return false;
	}
}