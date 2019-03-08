#pragma once

#include "Singleton.h"

/*
///////////////////////////////////////////
SettingProvider�N���X

�T�v�@�F�Q�[�����ʂ̏��(�X�N���[���T�C�Y�Ȃ�)���擾�ł���N���X
///////////////////////////////////////////
*/
class SettingProvider : public Singleton <SettingProvider>
{
	int stageNumber;

	bool isClear = false;

public:
	const int screenSizeX = 1920;
	const int screenSizeY = 1080;

	void SetStageNumber(int stageNum) { stageNumber = stageNum; }
	int GetStageNumber() { return stageNumber; }

	void SetClearFlg(bool clearFlg) { isClear = clearFlg; }
	bool GetIsClear() { return isClear; }
};