#pragma once
#include "RectShape.h"


/*
///////////////////////////////////////////
ObjectCollisionクラス

概要　：プレイヤーの当たり判定の管理
///////////////////////////////////////////
*/
class ObjectCollision
{
public:
	bool OnCollision(Rect myRect,Rect opponentRect);
};