#include "PlayerCollision.h"
#include "RectWatcher.h"
#include <vector>


/////////////////////////////////////////////////////
//引数			:プレイヤーと当たったオブジェクトの範囲を受け取りたいRect
//戻り値		:プレイヤーが当たっていたらtrue
//動作			:プレイヤーと当たっているかどうかを調べる
/////////////////////////////////////////////////////
bool PlayerCollision::OnCollision(Rect& collisionRect)
{
	Rect playerRect = RectWatcher::Instance()->GetPlayerRect();
	vector<Rect> rockRect = RectWatcher::Instance()->GetRockRect();
	vector<Rect> stageRect = RectWatcher::Instance()->GetStageRect();

	// for分で飛ばす
	if (objectCollision->OnCollision(playerRect,collisionRect)) return true;
	else return false;
}

