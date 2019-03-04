#pragma once

#include "Rock.h"
#include "RectShape.h"
#include "ObjectCollision.h"
#include "Player.h"

#include <vector>
#include <memory>


class RockCollision
{
	Rect rockRect;

	std::vector<std::unique_ptr<Rock>> rock;
	std::unique_ptr<ObjectCollision> objectCollision = std::make_unique<ObjectCollision>();

public:

	bool OnCollision();

	void SetCollisonRect(Rect rect);
};