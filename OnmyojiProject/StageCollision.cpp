#include "StageCollision.h"
#include "Collision.h"
#include "CollisionRectProvider.h"
#include "SettingProvider.h"

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
	CollisionRectProvider::Instance()->SetStageRect(collisionRange);
}

/////////////////////////////////////////////////////
//引数			:選択されたステージの壁の座標
//戻り値		:なし
//動作			:選択されたステージの当たり判定をセットする
/////////////////////////////////////////////////////
void StageCollision::SetCollsionPosition()
{
	int stageNum = SettingProvider::Instance()->GetStageNumber();
	vector<position> poss = StageInpoter::Instance()->GetStageCollisionData()[stageNum];

	collisionPos = poss;
	CollisionRangeSet();
}