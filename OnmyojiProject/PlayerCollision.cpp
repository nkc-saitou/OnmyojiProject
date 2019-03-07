#include "PlayerCollision.h"
#include "CollisionRectProvider.h"
#include <vector>

namespace PlayerScope
{
	/////////////////////////////////////////////////////
	//引数			:プレイヤーと当たったオブジェクトの範囲を受け取りたいRect
	//戻り値		:プレイヤーが当たっていたらtrue
	//動作			:プレイヤーと当たっているかどうかを調べる
	/////////////////////////////////////////////////////
	bool PlayerCollision::OnCollision(int x, int y)
	{
		Rect playerRect = CollisionRectProvider::Instance()->GetPlayerRect();
		std::vector<Rect> rockRect = CollisionRectProvider::Instance()->GetRockRect();
		std::vector<Rect> stageRect = CollisionRectProvider::Instance()->GetStageRect();

		// サイズを取得
		int rockRectCount = rockRect.size();
		int stageRectCount = stageRect.size();

		// ステージ上の壁と当たっているかどうか
		for (int i = 0; i < stageRectCount; i++)
		{
			if (objectCollision->OnCollision(playerRect, stageRect[i])) return true;
		}

		// ｘ方向、画面外に出ないように
		if (x + graphSize * 2 > screenSizeX) return true;
		if (x < graphSize) return true;

		// ｙ方向、画面外に出ないように
		if (y + graphSize * 2 > screenSizeY) return true;
		if (y < graphSize) return true;

		return false;
	}
}

