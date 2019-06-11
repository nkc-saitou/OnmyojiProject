#pragma once

/*
///////////////////////////////////////////
Input�N���X

�T�v�@�F���͊֘A�̏������܂Ƃ߂Ă���܂��B
�g�p��FInput::Instance()->ButtonDown(keyCode)
���Ӂ@�FMain���[�v����InputMemory()���ĂсA�ߋ����̎擾�𖈃t���[���s��
///////////////////////////////////////////
*/

#include "DxLib.h"
#include "Singleton.h"

//�{�^������
#define PAD_BUTTON_NUM 16

//�L�[�{�[�h���͗p�o�b�t�@�T�C�Y
#define KEY_STATE_BUFFER_SIZE 256

//�p�b�h�̑Ή��ԍ�
enum PadType
{
	Pad_1 = 1,
	Pad_2,
	Pad_3,
	Pad_4,
	Pad_5,
	Pad_6,
	Pad_7,
	Pad_8,
	Pad_9,
	Pad_10,
	Pad_11,
	Pad_12,
	Pad_13,
	Pad_14,
	Pad_15,
	Pad_16
};

class Input : public Singleton <Input>
{
	//�p�b�h�̓��͏�Ԃ��i�[
	XINPUT_STATE input[MAX_JOYPAD_NUM];
	XINPUT_STATE oldInput[MAX_JOYPAD_NUM];

	//�}�E�X�̓��͏�Ԃ��i�[
	int mouse;
	int oldMouse;

	//�L�[�̓��͏�Ԃ��i�[
	char oldKey[KEY_STATE_BUFFER_SIZE];
	char key[KEY_STATE_BUFFER_SIZE];

	//�S�Ă̓��͏�Ԃ��i�[
	int allInput;
	int oldAllInput;

	//�Ή��p�b�h
	int padInput = 0;

	//�p�b�h�z��̓Y���p�z��
	int padInputNum;

	//���͊p�x��ۑ�
	int InputX, InputY;

	//���͏�Ԃ��X�V
	void InputSetting();

	//�e�p�b�h�̓��͏�Ԃ��X�V
	void PadInputSetting(int padType);

	//�����ɗ^����ꂽkeyCode��padType�������͈͓����ǂ����𔻒f
	bool InputCheck(int keyCode, int padType = 0);

public:

	//�ߋ��̓��͏��̎擾
	void InputMemory();
	
	//���͊p�x�̎擾
	int AngleInputX(int padType);
	int AngleInputY(int padType);

	XINPUT_STATE PadState(int padType);

	//�p�b�h��U��������
	void PadStartVibration(int padType, int Power = 1000, int Time = -1);

	//�U�����Ă���p�b�h���~�߂�
	void PadStopVibration(int padType);

	//===�����œn����keyCode,padType�ʂ�ɂ���͂��Ă�����===

	//�{�^�����������u��
	bool ButtonDown(int keyCode, int padType = 0); 

	//�{�^���������Ă���Ƃ�
	bool Button(int keyCode, int padType = 0); 

	//�{�^���𗣂����u��
	bool ButtonUp(int keyCode, int padType = 0); 


	//=====�Ƃɂ�����������͂����Ă�����=====

	//���炩�̃{�^���������Ă���Ƃ�
	bool AnyButton();

	//���炩�̃{�^�����������u��
	bool AnyButtonDown();

	//���炩�̃{�^���𗣂����u��
	bool AnyButtonUp();


	//=====�ڑ�����Ă���p�b�h�̂����A
	//�ǂꂩ��ł�������keyCode����͂��Ă�����=====

	//�ǂꂩ�̃p�b�h���w��̃{�^���������Ă���Ƃ�
	bool PadAnyButton(int keyCode);

	//�ǂꂩ�̃p�b�h���w��̃{�^�����������u��
	bool PadAnyButtonDown(int keyCode);

	//�ǂꂩ�̃p�b�h���w��̃{�^���𗣂����u��
	bool PadAnyButonUp(int keyCode);
};
