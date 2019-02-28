#pragma once

#include "StageCollision.h"
#include "StageInpoter.h"

using namespace std;

class PlayerCollision
{
	unique_ptr<StageCollision> stageCollision = make_unique<StageCollision>();

	Rect playerRect;

public:

	bool OnCollision(Rect& collisionRect);

	void SetRockRect(int stageNum);

	void SetPlayerRect(Rect targetRect);

};