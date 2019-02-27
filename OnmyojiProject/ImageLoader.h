#pragma once

#include "Singleton.h"

/*
///////////////////////////////////////////
ImageDataIndex

�T�v�@�F�S�ẴC���[�W�f�[�^�̏��Ԃ��
///////////////////////////////////////////
*/
enum ImageDataIndex
{
	gameImage,
	toolImage,
	playerWalkImage,
	playerIdolImage,
	backImage,
	maxImage
};

/*
///////////////////////////////////////////
ImageLoader�N���X

�T�v�@�FImage�Ǘ��N���X
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
	const char* fileName[maxImage] =
	{
		"../OnmyojiProject/Image/TestMapChip5.png" ,
		"../OnmyojiProject/Image/TestMapChip4.png" ,
		"../OnmyojiProject/Image/PlayerRun.png" ,
		"../OnmyojiProject/Image/Player_idol.png",
		"../OnmyojiProject/Image/BackGround_1.png",
	};

	// �O���t�B�b�N�n���h��
	int gameStageGh[11];
	int toolStageGh[11];
	int playerWalkGh[16];
	int playerIdolGh[8];
	int backGroundGh;


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
	int GetBackGroundGH() { return backGroundGh; }
};