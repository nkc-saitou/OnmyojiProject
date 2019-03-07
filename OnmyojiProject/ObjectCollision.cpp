#include "ObjectCollision.h"
#include "Collision.h"


/////////////////////////////////////////////////////
//引数			:プレイヤーと当たったオブジェクトの範囲を受け取りたいRect
//戻り値		:プレイヤーが当たっていたらtrue
//動作			:プレイヤーと当たっているかどうかを調べる
/////////////////////////////////////////////////////
bool ObjectCollision::OnCollision(Rect myRect, Rect opponentRect)
{
	if (Collision::Instance()->CheckRectAndRect(myRect, opponentRect))
	{
		return true;
	}
	return false;
}