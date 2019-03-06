#pragma once

#include <vector>
#include "StageInpoter.h"
#include "RectShape.h"

using namespace std;

/*
///////////////////////////////////////////
StageCollisionクラス

概要　：ステージに設置されている動かない壁の当たり判定の管理
///////////////////////////////////////////
*/
class StageCollision
{
	vector<position> collisionPos;

	vector<Rect> collisionRange;

    const int graphSize = 64;

	// 当たり判定の範囲を設定
	void CollisionRangeSet();
public:

	// 選択されたステージの当たり判定情報を取得
	void SetCollsionPosition();
};