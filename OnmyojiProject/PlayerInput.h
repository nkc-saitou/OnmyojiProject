#pragma once

#include "E_PlayerDirection.h"

namespace PlayerScope
{
	class PlayerInput
	{
		int moveAngleInputX = 0;
		int moveAngleInputY = 0;

		bool isAction = false;

		Direction playerDir;

		void MoveInput();
		void ActionInput();

	public:

		void Update();

		bool GetIsAction() { return isAction; }

		int GetMoveAngleX() { return moveAngleInputX; }
		int GetMoveAngleY() { return moveAngleInputY; }
	};
}