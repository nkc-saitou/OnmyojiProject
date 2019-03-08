#include "RockCollision.h"
#include "SettingProvider.h"
#include "CollisionRectProvider.h"

#include "DxLib.h"

namespace RockScope 
{
	/////////////////////////////////////////////////////
	//引数			:ファイル名を格納するstring配列
	//戻り値		:なし
	//動作			:ステージデータの数とファイル名の取得
	/////////////////////////////////////////////////////
	bool RockCollision::OnCollision(Rect myRockRect, int x, int y, Rect& collisionRect, CollisionObjType& type)
	{
		Rect playerRect = CollisionRectProvider::Instance()->GetPlayerRect();
		std::vector<Rect> rockRect = CollisionRectProvider::Instance()->GetRockRect();
		std::vector<Rect> stageRect = CollisionRectProvider::Instance()->GetStageRect();
		std::vector<Rect> goalRect = CollisionRectProvider::Instance()->GetGoalRect();

		Rect topEdgeStageRect = CollisionRectProvider::Instance()->GetRightEdgeStageRect();
		Rect bottomEdgeStageRect = CollisionRectProvider::Instance()->GetLeftEdgeStageRect();
		Rect leftEdgeStageRect = CollisionRectProvider::Instance()->GetBottomEdgeStageRect();
		Rect rightEdgeStageRect = CollisionRectProvider::Instance()->GetTopEdgeStageRect();

		// 配列のサイズを取得
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

		// ステージ上のゴール地点と当たっているかどうか
		for (int i = 0; i < goalRect.size(); i++)
		{
			int temp = goalRect.size();

			if (objectCollision->OnCollision(myRockRect, goalRect[i]))
			{
				type = goal;
				collisionRect = goalRect[i];

				CollisionRectProvider::Instance()->RemoveGoalRectVec(i);

				for (int i = 0; i < rockRectCount; i++)
				{
					if (myRockRect.left == rockRect[i].left && myRockRect.top == rockRect[i].top)
					{
						CollisionRectProvider::Instance()->RemoveRockRectVec(i);
						break;
					}
				}

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