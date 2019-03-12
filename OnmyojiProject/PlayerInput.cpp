#include "PlayerInput.h"
#include "Input.h"

namespace PlayerScope
{
	void PlayerInput::MoveInput()
	{
		moveAngleInputX = Input::Instance()->AngleInputX(Pad_1);
		moveAngleInputY = Input::Instance()->AngleInputY(Pad_1);

		return;

		if (Input::Instance()->Button(KEY_INPUT_LEFT)) moveAngleInputX = -moveInputValue;
		else if (Input::Instance()->Button(KEY_INPUT_RIGHT)) moveAngleInputX = moveInputValue;
		else moveAngleInputX = 0;

		if (Input::Instance()->Button(KEY_INPUT_UP)) moveAngleInputY = -moveInputValue;
		else if (Input::Instance()->Button(KEY_INPUT_DOWN)) moveAngleInputY = moveInputValue;
		else moveAngleInputY = 0;


		// 斜め移動じゃない場合は終了
		if (moveAngleInputX == 0 || moveAngleInputY == 0) return;


		// 斜め移動の際の値を調整
		if (moveAngleInputX < 0)
		{
			if (moveAngleInputY > 0) moveAngleInputY = 700;
			if (moveAngleInputY < 0) moveAngleInputY = -700;

			moveAngleInputX = -700;
		}
		if (moveAngleInputX > 0)
		{
			if (moveAngleInputY > 0) moveAngleInputY = 700;
			if (moveAngleInputY < 0) moveAngleInputY = -700;

			moveAngleInputX = 700;
		}
	}

	void PlayerInput::ActionInput()
	{
		if (Input::Instance()->ButtonDown(XINPUT_BUTTON_A,Pad_1) || Input::Instance()->ButtonDown(KEY_INPUT_RETURN)) isAction = true;
		else isAction = false;

		if (Input::Instance()->ButtonDown(XINPUT_BUTTON_Y, Pad_1) || Input::Instance()->ButtonDown(KEY_INPUT_X)) isReset = true;
		else isReset = false;
	}

	void PlayerInput::Update()
	{
		MoveInput();
		ActionInput();
	}
}