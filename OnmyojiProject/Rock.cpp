#include "Rock.h"
#include "DxLib.h"
#include "ImageLoader.h"
#include "StageInpoter.h"
#include "E_CollisionObj.h"
#include "PlayerProvider.h"

namespace RockScope
{
	using namespace PlayerScope;

	void Rock::Move(Direction dir)
	{
		// ���ݓ������ԂłȂ��@�܂��́@���łɃS�[���ʒu�ɂ���ꍇ�͏I��
		if (isMove != true || isGoal != false) return;

		playerDir = dir;

		switch (dir)
		{
		case Direction::upDir:			y -= speed; break;
		case Direction::downDir:		y += speed; break;

		case Direction::leftDir:
		case Direction::upLeftDir:
		case Direction::downLeftDir:	x -= speed; break;

		case Direction::rightDir:
		case Direction::upRightDir:
		case Direction::downRightDir:	x += speed; break;
		}
	}

	void Rock::SetLayerData()
	{
		rendererData.x = x;
		rendererData.y = y;
		rendererData.gh = ImageLoader::Instance()->GetGameStageGH()[chip_rock];
		rendererData.orderInLayer = 0;
		rendererData.layerType = LayerType::object;
		rendererData.TransparencySortFlg = TRUE;
		rendererData.transFlg = TRUE;
	}


	void Rock::Draw()
	{
		SetLayerData();
		//DrawExtendGraph(x, y, x + graphSize, y + graphSize, ImageLoader::Instance()->GetGameStageGH()[chip_rock], TRUE);
	}


	void Rock::Collision()
	{
		Rect collisionRect;
		CollisionObjType collisionType;

		// �����ƂԂ������ہA�Ԃ������ꏊ���班�����炷
	    double backAdjust = 3.0;

		if (rockCollision->OnCollision(GetRect(), x, y, collisionRect, collisionType) 
			&& isMove == true && isGoal == false)
		{
			isMove = false;

			// �ǂɓ���������
			if (collisionType == CollisionObjType::wall)
			{
				// �O�͂𔭓������Ƃ��̃v���C���[�̌���
				switch (playerDir)
				{
				case Direction::upDir:			y += backMove * backAdjust; break;
				case Direction::downDir:		y -= backMove * backAdjust; break;

				case Direction::leftDir:
				case Direction::upLeftDir:
				case Direction::downLeftDir:	x += backMove * backAdjust; break;

				case Direction::rightDir:
				case Direction::upRightDir:
				case Direction::downRightDir:	x -= backMove * backAdjust; break;
				}
			}
			// ���̊�ɓ���������
			else if(collisionType == CollisionObjType::rock)
			{
				if		(GetRect().top < collisionRect.top)		y -= backMove * backAdjust;
				else if (GetRect().top > collisionRect.top)		y += backMove * backAdjust;
				else if (GetRect().left < collisionRect.left)	x -= backMove * backAdjust;
				else if (GetRect().left > collisionRect.left)	x += backMove * backAdjust;
			}
			// �ړI�n�ɐG�ꂽ��
			else if (collisionType == CollisionObjType::goal)
			{
				isGoal = true;
			}

			return;
		}
	}


	void Rock::RectSet()
	{
		double top		= y + offset;
		double bottom	= y + graphSize - offset;
		double left		= x + offset;
		double right	= x + graphSize - offset;

		SetValue(&top, &bottom, &left, &right);
	}


	void Rock::SetStartPos(double posX, double posY)
	{
		x = posX * graphSize;
		y = posY * graphSize;
	}


	void Rock::Update()
	{
		Collision();
		Draw();
		RectSet();
	}

}