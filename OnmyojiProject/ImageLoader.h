#pragma once

#include "Singleton.h"

/*
///////////////////////////////////////////
ImageDataIndex

�T�v�@�F�S�ẴC���[�W�f�[�^�̏��Ԃ��
///////////////////////////////////////////
*/
enum class ImageDataIndex
{
	gameImage,
	toolImage,
	playerWalkImage,
	playerIdolImage,
	backTitleImage,
	backGameImage,
	backClearImage,
	titlelogoImage,
	gameEffect,
	gameEffectMove,
	clearLogo,
	maxImage,
};

/*
///////////////////////////////////////////
ImageLoader�N���X

�T�v�@�FImage�Ǘ��N���X
����  �F�摜��ǉ�����ꍇ�AEnumClass�ł���ImageDataIndex�ɂ��ǉ��ŋL�ڂ��邱��
///////////////////////////////////////////
*/
class ImageLoader : public Singleton <ImageLoader>
{
	//===============================
	// �ϐ�
	//===============================

	// Image��Path
	const char* path = "../OnmyojiProject/Image/";

	// �t�@�C���l�[��
	const char* fileName[(int)ImageDataIndex::maxImage] =
	{
		"../OnmyojiProject/Image/TestMapChip5.png" ,
		"../OnmyojiProject/Image/TestMapChip4.png" ,
		"../OnmyojiProject/Image/PlayerRun.png" ,
		"../OnmyojiProject/Image/Player_idol.png",
		"../OnmyojiProject/Image/titleBack.png",
		"../OnmyojiProject/Image/BackGround_1.png",
		"../OnmyojiProject/Image/BackGround.png",
		"../OnmyojiProject/Image/star.png",
		"../OnmyojiProject/Image/gameEfefct.png",
		"../OnmyojiProject/Image/gameEfefctMove.png",
		"../OnmyojiProject/Image/ClearLogo.png",
	};

	// �O���t�B�b�N�n���h��
	int gameStageGh[11];
	int toolStageGh[11];
	int playerWalkGh[16];
	int playerIdolGh[8];
	int backTitleGroundGh;
	int backGroundGh;
	int backClearGroundGh;
	int titlelogoGh;
	int gameEffectGh;
	int gameEffectMoveGh;
	int clearLogoGh;


	//===============================
	// �֐�
	//===============================
public:

	void ImageDiv();

	//===============================
	// �Q�b�^�[
	//===============================
	int* GetGameStageGH() { return gameStageGh; }
	int* GetToolStageGH() { return toolStageGh; }
	int* GetPlayerWalkGH() { return playerWalkGh; }
	int* GetPlayerIdolGH() { return playerIdolGh; }
	int GetBackTitleGroundGh() { return backTitleGroundGh; }
	int GetBackGroundGH() { return backGroundGh; }
	int GetBackClearGroundGh() { return backClearGroundGh; }
	int GetTitleLogoGh() { return titlelogoGh; }
	int GetGameEffectGh() { return gameEffectGh; }
	int GetGameEffectMoveGh() { return gameEffectMoveGh; }
	int GetClearLogoGh() { return clearLogoGh; }
};