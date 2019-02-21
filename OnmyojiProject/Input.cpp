#include "Input.h"

/////////////////////////////////////////////////////
//����			:���̓L�[�R�[�h�A�Ή��p�b�h(�f�t�H���g�����͂O(�L�[����))
//�߂�l		:�����̃L�[��������Ă����true
//����			:�����̃L�[��������Ă��邩�𔻒�
/////////////////////////////////////////////////////
bool Input::Button(int keyCode, int padType)
{
	//�����Ȑ��l�����͂���Ă��Ȃ����ǂ���
	if (InputCheck(keyCode, padType) == false) return false;

	//���͏�Ԃ��X�V
	InputSetting();
	PadInputSetting(padType);

	//�L�[���͏���
	if(key[keyCode] != 0) return true;

	//�}�E�X���͏���
	if ((mouse & keyCode) == keyCode) return true;

	//�p�b�h���͏���
	if (input[padInputNum].Buttons[keyCode] != 0) return true;

	return false;
}

/////////////////////////////////////////////////////
//����			:���̓L�[�R�[�h�A�Ή��p�b�h(�f�t�H���g�����͂O(�L�[����))
//�߂�l		:�����̃L�[�������ꂽ�u�Ԃ̂�true
//����			:�����̃L�[�������ꂽ�u�Ԃ𔻒�
/////////////////////////////////////////////////////
bool Input::ButtonDown(int keyCode, int padType)
{
	//�����Ȑ��l�����͂���Ă��Ȃ����ǂ���
	if (InputCheck(keyCode, padType) == false) return false;

	//���͏�Ԃ��X�V
	InputSetting();
	PadInputSetting(padType);

	//�L�[���͏���
	if (oldKey[keyCode] == 0 &&
		key[keyCode] != 0) return true;

	//�}�E�X���͏���
	if ((oldMouse & keyCode) == 0 &&
		(mouse & keyCode) == keyCode) return true;
	
	//�p�b�h���͏���
	if (oldInput[padInputNum].Buttons[keyCode] == 0 &&
		input[padInputNum].Buttons[keyCode] != 0) return true;

	return false;
}

/////////////////////////////////////////////////////
//����			:���̓L�[�R�[�h�A�Ή��p�b�h(�f�t�H���g�����͂O(�L�[����))
//�߂�l		:�����̃L�[�������ꂽ�u�Ԃ̂�true
//����			:�����̃L�[�������ꂽ�u�Ԃ𔻒�
/////////////////////////////////////////////////////
bool Input::ButtonUp(int keyCode, int padType)
{
	//�����Ȑ��l�����͂���Ă��Ȃ����ǂ���
	if (InputCheck(keyCode, padType) == false) return false;

	//���͏�Ԃ��X�V
	InputSetting();
	PadInputSetting(padType);

	//�L�[���͏���
	if (oldKey[keyCode] != 0 &&
		key[keyCode] == 0) return true;

	//�}�E�X���͏���
	if ((oldMouse & keyCode) == keyCode &&
		(mouse & keyCode) == 0) return true;

	//�p�b�h���͏���
	if (oldInput[padInputNum].Buttons[keyCode] != 0 &&
		input[padInputNum].Buttons[keyCode] == 0) return true;

	return false;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:���炩�̃L�[��������Ă��鎞��true
//����			:��������̃L�[��������Ă��邩�𔻒�
/////////////////////////////////////////////////////
bool Input::AnyButton()
{
	//���͏�Ԃ��X�V
	InputSetting();

	//������Ă��邩�𔻒�
	if (allInput != 0) return true;
	return false;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:���炩�̃L�[�������ꂽ�u�Ԃ̂�true
//����			:��������̃L�[�������ꂽ�u�Ԃ𔻒�
/////////////////////////////////////////////////////
bool Input::AnyButtonDown()
{
	//���͏�Ԃ��X�V
	InputSetting();

	//�P�t���[���O�ƌ��݃t���[�����ׂ�
	if (oldAllInput == 0 &&
		allInput != 0) return true;

	return false;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:���炩�̃L�[�������ꂽ�u�Ԃ̂�true
//����			:��������̃L�[�������ꂽ�u�Ԃ𔻒�
/////////////////////////////////////////////////////
bool Input::AnyButtonUp()
{
	//���͏�Ԃ��X�V
	InputSetting();

	//�P�t���[���O�ƌ��݃t���[�����ׂ�
	if (oldAllInput != 0 &&
		allInput == 0) return true;

	return false;
}

/////////////////////////////////////////////////////
//����			:���̓L�[�R�[�h
//�߂�l		:�p�b�h�{�^����������Ă��鎞true
//����			:�p�b�h�{�^����������Ă��邩�ǂ����𔻒�
/////////////////////////////////////////////////////
bool Input::PadAnyButton(int keyCode)
{
	//�S�Ẵp�b�h�𒲂ׂ�
	for (int i = 1; i <= MAX_JOYPAD_NUM; i++)
	{
		//�p�b�h�̓��͏�Ԃ𒲂ׂ�
		PadInputSetting(i);

		//�{�^����������Ă��邩�ǂ���
		if (input[padInputNum].Buttons[keyCode] != 0) return true;
	}

	return false;
}

/////////////////////////////////////////////////////
//����			:���̓L�[�R�[�h
//�߂�l		:�����̃{�^���������ꂽ�u�Ԃ̂�true
//����			:�ڑ�����Ă���ǂꂩ�̃p�b�h�́A�w��̃{�^���������ꂽ�u�Ԃ𔻒�
/////////////////////////////////////////////////////
bool Input::PadAnyButtonDown(int keyCode)
{
	//�S�Ẵp�b�h�𒲂ׂ�
	for (int i = 1; i <= MAX_JOYPAD_NUM; i++)
	{
		//�p�b�h�̓��͏�Ԃ𒲂ׂ�
		PadInputSetting(i);

		if (oldInput[padInputNum].Buttons[keyCode] == 0 &&
			input[padInputNum].Buttons[keyCode] != 0) return true;
	}

	return false;
}

/////////////////////////////////////////////////////
//����			:���̓L�[�R�[�h
//�߂�l		:�����̃{�^���������ꂽ�u�Ԃ̂�true
//����			:�ڑ�����Ă���ǂꂩ�̃p�b�h�́A�w��̃{�^���������ꂽ�u�Ԃ𔻒�
/////////////////////////////////////////////////////
bool Input::PadAnyButonUp(int keyCode)
{
	//�S�Ẵp�b�h�𒲂ׂ�
	for (int i = 1; i <= MAX_JOYPAD_NUM; i++)
	{
		//�p�b�h�̓��͏�Ԃ𒲂ׂ�
		PadInputSetting(i);

		if (oldInput[padInputNum].Buttons[keyCode] != 0 &&
			input[padInputNum].Buttons[keyCode] == 0) return true;
	}

	return false;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:���݂̓��͏�Ԃ��i�[
/////////////////////////////////////////////////////
void Input::InputSetting()
{
	//�L�[�{�[�h�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(key);

	//�}�E�X�̓��͏�Ԃ𓾂�
	mouse = GetMouseInput();

	//�S��(�L�[�{�[�h�A�}�E�X�A�p�b�h)�̓��͏�Ԃ𓾂�
	allInput = CheckHitKeyAll(DX_CHECKINPUT_ALL);

}

/////////////////////////////////////////////////////
//����			:�U��������p�b�h�A�U���̋���(�f�t�H���g��1000)�A�U�������鎞��(�f�t�H���g��-1(PadStopVibration���ĂԂ܂Ŏ~�܂�Ȃ�))
//�߂�l		:�Ȃ�
//����			:�U��������
/////////////////////////////////////////////////////
void Input::PadStartVibration(int padType, int Power, int Time)
{
	PadInputSetting(padType);
	StartJoypadVibration(padInput, Power, Time);
}

/////////////////////////////////////////////////////
//����			:�U�����Ƃ߂�p�b�h
//�߂�l		:�Ȃ�
//����			:�U�����~�߂�
/////////////////////////////////////////////////////
void Input::PadStopVibration(int padType)
{
	PadInputSetting(padType);
	StopJoypadVibration(padInput);
}

/////////////////////////////////////////////////////
//����			:�Ή��p�b�h
//�߂�l		:�Ȃ�
//����			:�W���C�p�b�h�̃A�i���O�I�ȃ��o�[���͏���X���𓾂�
/////////////////////////////////////////////////////
int Input::AngleInputX(int padType)
{
	if (padType <= 0) return 0;

	PadInputSetting(padType);

	float angleInput_x = InputX;
	
	return angleInput_x;
}

/////////////////////////////////////////////////////
//����			:�Ή��p�b�h
//�߂�l		:�Ȃ�
//����			:�W���C�p�b�h�̃A�i���O�I�ȃ��o�[���͏���Y���𓾂�
/////////////////////////////////////////////////////
int Input::AngleInputY(int padType)
{
	if (padType <= 0) return 0;

	PadInputSetting(padType);

	float angleInput_y = InputY;

	return angleInput_y;
}

/////////////////////////////////////////////////////
//����			:�Ή��p�b�h
//�߂�l		:�Ȃ�
//����			:���݂̊e�p�b�h�̓��͏�Ԃ��i�[
/////////////////////////////////////////////////////
void Input::PadInputSetting(int padType)
{
	if (padType <= 0) return;

	//�Ή��p�b�h�𔻕�
	switch (padType)
	{
	case Pad_1:  padInput = DX_INPUT_PAD1;  break;
	case Pad_2:  padInput = DX_INPUT_PAD2;  break;
	case Pad_3:  padInput = DX_INPUT_PAD3;  break;
	case Pad_4:  padInput = DX_INPUT_PAD4;  break;
	case Pad_5:  padInput = DX_INPUT_PAD5;  break;
	case Pad_6:  padInput = DX_INPUT_PAD6;  break;
	case Pad_7:  padInput = DX_INPUT_PAD7;  break;
	case Pad_8:  padInput = DX_INPUT_PAD8;  break;
	case Pad_9:  padInput = DX_INPUT_PAD9;  break;
	case Pad_10: padInput = DX_INPUT_PAD10; break;
	case Pad_11: padInput = DX_INPUT_PAD11; break;
	case Pad_12: padInput = DX_INPUT_PAD12; break;
	case Pad_13: padInput = DX_INPUT_PAD13; break;
	case Pad_14: padInput = DX_INPUT_PAD14; break;
	case Pad_15: padInput = DX_INPUT_PAD15; break;
	case Pad_16: padInput = DX_INPUT_PAD16; break;
	}

	//�p�b�h�z��ɓ��͏�Ԃ��i�[���邽�߂̓Y��
	padInputNum = padType - 1;

	// �p�b�h�̓��͏�Ԃ��擾
	GetJoypadXInputState(padInput, &input[padInputNum]);

	//�A�i���O�p�b�h�̓��͏�Ԃ��擾
	GetJoypadAnalogInput(&InputX, &InputY, padInput);
}

/////////////////////////////////////////////////////
//����			:���͂��ꂽ�L�[�R�[�h�A�p�b�h(�f�t�H���g�����͂O)
//�߂�l		:�͈͂𒴂������l�������ꍇfalse
//����			:�����œn���ꂽ���l�������͈͓��̐��l���ǂ����𔻒f
/////////////////////////////////////////////////////
bool Input::InputCheck(int keyCode, int padType)
{
	if (padType == 0 && keyCode > KEY_STATE_BUFFER_SIZE) return false;
	if (padType != 0 && keyCode > PAD_BUTTON_NUM) return false;
	if (padType > MAX_JOYPAD_NUM || padType < 0) return false;

	return true;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�ߋ��̓��͏����i�[
/////////////////////////////////////////////////////
void Input::InputMemory()
{
	oldMouse = mouse;
	memcpy(oldKey, key, sizeof(key));
	memcpy(oldInput, input, sizeof(input));
	oldAllInput = allInput;
}