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

	// �I�����ꂽ�X�e�[�W�̓����蔻������擾
	void SetCollsionPosition(vector<position> pos);
};