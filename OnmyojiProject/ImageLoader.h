#pragma once

#include "Singleton.h"

/*
///////////////////////////////////////////
ImageDataIndex

概要　：全てのイメージデータの順番を列挙
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
ImageLoaderクラス

概要　：Image管理クラス
注意  ：画像を追加する場合、EnumClassであるImageDataIndexにも追加で記載すること
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

	// グラフィックハンドル
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
	int GetBackTitleGroundGh() { return backTitleGroundGh; }
	int GetBackGroundGH() { return backGroundGh; }
	int GetBackClearGroundGh() { return backClearGroundGh; }
	int GetTitleLogoGh() { return titlelogoGh; }
	int GetGameEffectGh() { return gameEffectGh; }
	int GetGameEffectMoveGh() { return gameEffectMoveGh; }
	int GetClearLogoGh() { return clearLogoGh; }
};