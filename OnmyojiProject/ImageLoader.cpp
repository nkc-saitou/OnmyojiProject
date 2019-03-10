#include "ImageLoader.h"
#include "DxLib.h"

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:Imageのロード
/////////////////////////////////////////////////////
void ImageLoader::ImageDiv()
{
	LoadDivGraph(fileName[gameImage], 11, 6, 2, 128, 128, gameStageGh);
	LoadDivGraph(fileName[toolImage], 11, 6, 2, 128, 128, toolStageGh);
	LoadDivGraph(fileName[playerWalkImage], 16, 4, 4, 64, 64, playerWalkGh);
	LoadDivGraph(fileName[playerIdolImage], 8, 2, 4, 64, 64, playerIdolGh);

	backGroundGh = LoadGraph(fileName[backImage]);
	titlelogoGh = LoadGraph(fileName[titlelogoImage]);
}