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

		// サイズを取得
		int rockRectCount = rockRect.size();
		int stageRectCount = stageRect.size();

		if (objectCollision->OnCollision(myRockRect, playerRect))
		{
			type = player;
			return true;
		}

		// 石と当たっているかどうか
		for (int i = 0; i < rockRectCount; i++)
		{
			// 今見ているオブジェクト(myRockRectを持つ石)と、
			// rockRect配列に含まれているオブジェクト(rockRect[i]を持つ石)が同じだった場合は当たり判定を調べない
			if (myRockRect.left == rockRect[i].left && myRockRect.top == rockRect[i].top) continue;

			if (objectCollision->OnCollision(myRockRect, rockRect[i]))
			{
				type = rock;
				collisionRect = rockRect[i];
				return true;
			}
		}

		// ステージ上の壁と当たっているかどうか
		for (int i = 0; i < stageRectCount; i++)
		{
			if (objectCollision->OnCollision(myRockRect, stageRect[i]))
			{
				type = wall;
				collisionRect = stageRect[i];
				return true;
			}
		}

		// ｘ方向、画面外に出ないように
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

		// ｙ方向、画面外に出ないように
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