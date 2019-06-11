#include "Rock.h"
#include "DxLib.h"
#include "ImageLoader.h"
#include "StageInpoter.h"
#include "E_CollisionObj.h"
#include "PlayerProvider.h"

namespace RockScope
{
	using namespace PlayerScope;

	/////////////////////////////////////////////////////
	//引数			:移動方向
	//戻り値		:なし
	//動作			:岩が動く挙動
	/////////////////////////////////////////////////////
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

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:描画
	/////////////////////////////////////////////////////
	void Rock::Draw()
	{
		DrawExtendGraph(x, y, x + graphSize, y + graphSize, ImageLoader::Instance()->GetGameStageGH()[chip_rock], TRUE);
	}


	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:当たり判定
	/////////////////////////////////////////////////////
	void Rock::Collision()
	{
		Rect collisionRect;
		CollisionObjType collisionType;

		// 何かとぶつかった際、ぶつかった場所から少しずらす
	    double backAdjust = 3.0;

		if (rockCollision->OnCollision(GetRect(), x, y, collisionRect, collisionType) 
			&& isMove == true && isGoal == false)
		{
			isMove = false;

			// 壁に当たった時
			if (collisionType == CollisionObjType::wall)
			{
				// 念力を発動したときのプレイヤーの向き
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
			// 他の岩に当たった時
			else if(collisionType == CollisionObjType::rock)
			{
				if		(GetRect().top < collisionRect.top)		y -= backMove * backAdjust;
				else if (GetRect().top > collisionRect.top)		y += backMove * backAdjust;
				else if (GetRect().left < collisionRect.left)	x -= backMove * backAdjust;
				else if (GetRect().left > collisionRect.left)	x += backMove * backAdjust;
			}
			// 目的地に触れた時
			else if (collisionType == CollisionObjType::goal)
			{
				isGoal = true;
			}

			return;
		}
	}

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:当たり判定の範囲をセット
	/////////////////////////////////////////////////////
	void Rock::RectSet()
	{
		double top		= y + offset;
		double bottom	= y + graphSize - offset;
		double left		= x + offset;
		double right	= x + graphSize - offset;

		SetValue(&top, &bottom, &left, &right);
	}

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:初期位置をセット
	/////////////////////////////////////////////////////
	void Rock::SetStartPos(double posX, double posY)
	{
		x = posX * graphSize;
		y = posY * graphSize;
	}

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:更新
	/////////////////////////////////////////////////////
	void Rock::Update()
	{
		Collision();
		Draw();
		RectSet();
	}

}