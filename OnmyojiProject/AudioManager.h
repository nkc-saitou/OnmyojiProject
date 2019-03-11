#pragma once
#include "Singleton.h"

/*
///////////////////////////////////////////
ImageDataIndex

�T�v�@�F�S�ẴC���[�W�f�[�^�̏��Ԃ��
///////////////////////////////////////////
*/
enum BGMDataIndex
{
	titleBGM,
	gameBGM,
	resultBGM,
	maxBGM
};

enum SEDataIndex
{
	walkSE,
	maxSE
};

class AudioManager : public Singleton<AudioManager>
{
	// �t�@�C���l�[��
	const char* fileBGMName[maxBGM] =
	{
		"../OnmyojiProject/Sound/BGM/title.mp3" ,
		"../OnmyojiProject/Sound/BGM/game.mp3" ,
		"../OnmyojiProject/Sound/BGM/result.mp3" ,
	};

	// �t�@�C���l�[��
	const char* fileSEName[maxSE] =
	{
		"../OnmyojiProject/Image/TestMapChip5.png" ,
	};

	// �T�E���h�n���h��
	int b_titleSh;
	int b_gameSh;
	int b_resultSh;

	int s_playerWalkSh;

	int bgmMemorySh;


	//===============================
	// �֐�
	//===============================
public:

	void LoadSound();

	void PlayBGM(int sh,int volume = 125);
	void PlaySE(int sh,int volume = 125);

	//===============================
	// �Q�b�^�[
	//===============================
	int GetBGM_TitleSH() { return b_titleSh; }
	int GetBGM_GameSh() { return b_gameSh; }
	int GetBGM_ResultSh() { return b_resultSh; }

	int GetSE_PlayerWalkSh() { return s_playerWalkSh; }
};