#pragma once

#include "E_PlayerDirection.h"

namespace PlayerScope
{
	/*
	///////////////////////////////////////////
	PlayerInputクラス

	概要　：プレイやーの入力を管理するクラス
	///////////////////////////////////////////
	*/
	class PlayerInput
	{
		const int moveInputValue = 1000;

		int moveAngleInputX = 0;
		int moveAngleInputY = 0;

		bool isAction = false;
		bool isReset = false;

		Direction playerDir;

		void MoveInput();
		void ActionInput();

	public:

		void Update();

		bool GetIsAction() { return isAction; }

		bool GetIsReset() { return isReset; }

		int GetMoveAngleX() { return moveAngleInputX; }
		int GetMoveAngleY() { return moveAngleInputY; }
	};
}