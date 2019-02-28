#pragma once

#include <vector>
#include "StageInpoter.h"
#include "RectShape.h"

using namespace std;

class StageCollision
{
	vector<position> collisionPos;

	vector<Rect> collisionRange;

	int graphSize = 64;

	int count = 0;


	void CollisionRangeSet();
public:

	bool OnCollision(Rect targetRect);

	// 選択されたステージの当たり判定情報を取得
	void SetCollsionPosition(vector<position> pos);
};