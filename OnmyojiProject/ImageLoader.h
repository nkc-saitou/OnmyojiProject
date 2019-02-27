#pragma once

#include "Singleton.h"

/*
///////////////////////////////////////////
ImageDataIndex

概要　：全てのイメージデータの順番を列挙
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
ImageLoaderクラス

概要　：Image管理クラス
///////////////////////////////////////////
*/
class ImageLoader : public Singleton <ImageLoader>
{
	//===============================
	// 変数
	//===============================

	// ImageのPath
	const char* path = "../OnmyojiProject/Image/";

	// ファイルネーム
	const char* fileName[maxImage] =
	{
		"../OnmyojiProject/Image/TestMapChip5.png" ,
		"../OnmyojiProject/Image/TestMapChip4.png" ,
		"../OnmyojiProject/Image/PlayerRun.png" ,
		"../OnmyojiProject/Image/Player_idol.png",
		"../OnmyojiProject/Image/BackGround_1.png",
	};

	// グラフィックハンドル
	int gameStageGh[11];
	int toolStageGh[11];
	int playerWalkGh[16];
	int playerIdolGh[8];
	int backGroundGh;


	//===============================
	// 関数
	//===============================
public:

	void ImageDiv();

	//===============================
	// ゲッター
	//===============================
	int* GetGameStageGH() { return gameStageGh; }
	int* GetToolStageGH() { return toolStageGh; }
	int* GetPlayerWalkGH() { return playerWalkGh; }
	int* GetPlayerIdolGH() { return playerIdolGh; }
	int GetBackGroundGH() { return backGroundGh; }
};