#include "ImageLoader.h"
#include "DxLib.h"


void ImageLoader::ImageDiv()
{
	LoadDivGraph(fileName[gameImage], 11, 6, 2, 128, 128, gameStageGh);
	LoadDivGraph(fileName[toolImage], 11, 6, 2, 128, 128, toolStageGh);
	LoadDivGraph(fileName[playerWalkImage], 12, 3, 4, 64, 64, playerWalkGh);
	LoadDivGraph(fileName[playerIdolImage], 8, 2, 4, 64, 64, playerIdolGh);

	backGroundGh = LoadGraph(fileName[backImage]);
}