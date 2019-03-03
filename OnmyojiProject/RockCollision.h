#pragma once
#include "RectShape.h"
#include "StageCollision.h"
#include "PlayerCollision.h"

class RockCollision
{
	unique_ptr<StageCollision> stageCollision = make_unique<StageCollision>();
	unique_ptr<PlayerCollision> playerCollision = make_unique<PlayerCollision>();

	Rect targetRect;

public:

	bool OnCollision(Rect& collisionRect);

	void SetCollisonRect(Rect rect);
};