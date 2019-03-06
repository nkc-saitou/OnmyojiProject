#include "PlayerInput.h"
#include "Input.h"

namespace PlayerScope
{
	void PlayerInput::MoveInput()
	{
		moveAngleInputX = Input::Instance()->AngleInputX(Pad_1);
		moveAngleInputY = Input::Instance()->AngleInputY(Pad_1);
	}

	void PlayerInput::ActionInput()
	{
		if (Input::Instance()->ButtonDown(XINPUT_BUTTON_A,Pad_1)) isAction = true;
		else isAction = false;
	}

	void PlayerInput::Update()
	{
		MoveInput();
		ActionInput();
	}
}