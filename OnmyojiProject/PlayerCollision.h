#pragma once

#include "StageInpoter.h"
#include "ObjectCollision.h"

using namespace std;

// 相互参照のため前方宣言
class RockCollision;
/*
///////////////////////////////////////////
PlayerCollisionクラス

概要　：プレイヤーの当たり判定の管理
///////////////////////////////////////////
*/
class PlayerCollision
{
	unique_ptr<ObjectCollision> objectCollision = make_unique<ObjectCollision>();



public:


	// 何かにあたったかどうか
	bool OnCollision(Rect& collisionRect);

};