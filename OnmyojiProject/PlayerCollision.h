#pragma once

#include "StageCollision.h"
#include "StageInpoter.h"

using namespace std;

/*
///////////////////////////////////////////
PlayerCollisionクラス

概要　：プレイヤーの当たり判定の管理
///////////////////////////////////////////
*/
class PlayerCollision
{
	unique_ptr<StageCollision> stageCollision = make_unique<StageCollision>();

	Rect playerRect;

public:

	// 何かにあたったかどうか
	bool OnCollision(Rect& collisionRect);

	// 岩の当たり判定をセット
	void SetRockRect(int stageNum);

	// プレイヤーの当たり判定をセット
	void SetPlayerRect(Rect targetRect);

};