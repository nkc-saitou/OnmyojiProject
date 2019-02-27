#pragma once

#include "Singleton.h"

enum ImageDataIndex
{
	gameImage,
	toolImage,
	playerWalkImage,
	playerIdolImage,
	backImage,
	maxImage
};

class ImageLoader : public Singleton <ImageLoader>
{

	const char* path = "../OnmyojiProject/Image/";

	const char* fileName[maxImage] =
	{
		"../OnmyojiProject/Image/TestMapChip5.png" ,
		"../OnmyojiProject/Image/TestMapChip4.png" ,
		"../OnmyojiProject/Image/PlayerRun.png" ,
		"../OnmyojiProject/Image/Player_idol.png",
		"../OnmyojiProject/Image/BackGround_1.png",
	};


	int gameStageGh[11];
	int toolStageGh[11];
	int playerWalkGh[16];
	int playerIdolGh[8];
	int backGroundGh;


public:

	void ImageDiv();

	int* GameStageGH() { return gameStageGh; }
	int* ToolStageGH() { return toolStageGh; }
	int* PlayerWalkGH() { return playerWalkGh; }
	int* PlayerIdolGH() { return playerIdolGh; }
	int BackGroundGH() { return backGroundGh; }
};