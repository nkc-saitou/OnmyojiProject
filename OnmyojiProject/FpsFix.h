#pragma once

#include <math.h>
#include "DxLib.h"

class FpsFix
{
	//����J�n����
	int startTime = 0;
	// �J�E���^�[
	int count = 0;
	// fps
	float fps = 0;

	// �Œ��fps
	static const int fixFps = 60;
	// ���ς�fps
	static const int averageFps = 60;

public:
	// ���t���[���X�V
	void FpsCounter();
	// Fps�`��
	void Draw();
	// �Œ�Fps�őҋ@����
	void Wait();
};