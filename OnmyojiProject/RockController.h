#pragma once

#include <vector>
#include <memory>

#include "Rock.h"
#include "PlayerInput.h"

namespace RockScope
{
	/*
	///////////////////////////////////////////
	RockControlerクラス

	概要　：石オブジェクト全体の制御
	///////////////////////////////////////////
	*/

	class RockController
	{
		std::vector<std::unique_ptr<Rock>> rock;

		std::unique_ptr<PlayerScope::PlayerInput> playerInput = std::make_unique<PlayerScope::PlayerInput>();

		PlayerScope::Direction dir;

	public:

		// 岩の初期位置をセット
		void RockStartPosSet(int stageNum);

		// 岩の当たり判定をセット
		void RockCollisonSet();

		// 更新
		void Update();

	};
}