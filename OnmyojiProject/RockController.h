#pragma once

#include <vector>
#include <memory>

#include "Rock.h"
#include "PlayerInput.h"

namespace RockScope
{
	class RockController
	{
		std::vector<std::unique_ptr<Rock>> rock;

		std::unique_ptr<PlayerScope::PlayerInput> playerInput = std::make_unique<PlayerScope::PlayerInput>();

		int stageNum = 0;

		bool isMove = false;

		PlayerScope::Direction dir;

	public:

		void RockStartPosSet(int stageNum);

		void RockCollisonSet();

		void Update();

	};
}