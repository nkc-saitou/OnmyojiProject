#include "StageCollision.h"
#include "Collision.h"

#include "DxLib.h"

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:当たり判定の範囲を設定
/////////////////////////////////////////////////////
void StageCollision::CollisionRangeSet()
{
	const int offset = 5;
	for (int i = 0; i < collisionPos.size(); i++)
	{
		Rect tempRect;

		// あたり判定の位置を融通させる
		tempRect.top = collisionPos[i].y * graphSize + offset;
		tempRect.left = collisionPos[i].x * graphSize + offset;
		tempRect.bottom = tempRect.top + graphSize - offset;
		tempRect.right = tempRect.left + graphSize - offset * 2;

		collisionRange.push_back(tempRect);
	}
}

/////////////////////////////////////////////////////
//引数			:当たり判定を調べたいオブジェクトのRect , あたったオブジェクトのRect
//戻り値		:当たっていたらtrue
//動作			:引数で与えたオブジェクトと、動かない壁が当たっているかどうかを調べる。
//               当たっていた場合は、当たった壁のRectを渡す
/////////////////////////////////////////////////////
bool StageCollision::OnCollision(Rect playerRect, Rect& collisionRect)
{
	for (int i = 0; i < collisionRange.size(); i++)
	{
		if (Collision::Instance()->CheckRectAndRect(playerRect, collisionRange[i]))
		{
			collisionRect = collisionRange[i];
			return true;
		}
	}

	return false;
}

/////////////////////////////////////////////////////
//引数			:選択されたステージの壁の座標
//戻り値		:なし
//動作			:選択されたステージの当たり判定をセットする
/////////////////////////////////////////////////////
void StageCollision::SetCollsionPosition(vector<position> pos)
{
	collisionPos = pos;
	CollisionRangeSet();
}