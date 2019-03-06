#pragma once

#include "StageInpoter.h"
#include "ObjectCollision.h"
#include "SettingProvider.h"

namespace PlayerScope
{
	/*
	///////////////////////////////////////////
	PlayerCollisionクラス

	概要　：プレイヤーの当たり判定の管理
	///////////////////////////////////////////
	*/
	class PlayerCollision
	{
		std::unique_ptr<ObjectCollision> objectCollision = std::make_unique<ObjectCollision>();

		const int graphSize = 64;
		const int screenSizeX = SettingProvider::Instance()->screenSizeX;
		const int screenSizeY = SettingProvider::Instance()->screenSizeY;

	public:

		// 何かにあたったかどうか
		bool OnCollision(int x, int y);
	};
}