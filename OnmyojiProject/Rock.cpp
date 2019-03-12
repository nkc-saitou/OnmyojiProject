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
		// 現在動ける状態でない　または　すでにゴール位置にいる場合は終了
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


	void Rock::Draw()
	{
		DrawExtendGraph(x, y, x + graphSize, y + graphSize, ImageLoader::Instance()->GetGameStageGH()[chip_rock], TRUE);
	}


	void Rock::Collision()
	{
		Rect collisionRect;
		CollisionObjType collisionType;

		if (rockCollision->OnCollision(GetRect(), x, y, collisionRect, collisionType) 
			&& isMove == true && isGoal == false)
		{
			isMove = false;

			if (collisionType == wall)
			{
				// 念力を発動したときのプレイヤーの向き
				switch (playerDir)
				{
				case Direction::upDir:			y += backMove * 2.0; break;
				case Direction::downDir:		y -= backMove * 2.0; break;

				case Direction::leftDir:
				case Direction::upLeftDir:
				case Direction::downLeftDir:	x += backMove * 2.0; break;

				case Direction::rightDir:
				case Direction::upRightDir:
				case Direction::downRightDir:	x -= backMove * 2.0; break;
				}
			}
			else if(collisionType == rock)
			{
				if		(GetRect().top < collisionRect.top)		y -= backMove * 2.0;
				else if (GetRect().top > collisionRect.top)		y += backMove * 2.0;
				else if (GetRect().left < collisionRect.left)	x -= backMove * 2.0;
				else if (GetRect().left > collisionRect.left)	x += backMove * 2.0;
			}
			else if (collisionType == goal)
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