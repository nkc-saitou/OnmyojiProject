#include "ImageLoader.h"
#include "DxLib.h"

/////////////////////////////////////////////////////
//à¯êî			:Ç»Çµ
//ñﬂÇËíl		:Ç»Çµ
//ìÆçÏ			:ImageÇÃÉçÅ[Éh
/////////////////////////////////////////////////////
void ImageLoader::ImageDiv()
{
	LoadDivGraph(fileName[(int)ImageDataIndex::gameImage], 11, 6, 2, 128, 128, gameStageGh);
	LoadDivGraph(fileName[(int)ImageDataIndex::toolImage], 11, 6, 2, 128, 128, toolStageGh);
	LoadDivGraph(fileName[(int)ImageDataIndex::playerWalkImage], 16, 4, 4, 64, 64, playerWalkGh);
	LoadDivGraph(fileName[(int)ImageDataIndex::playerIdolImage], 8, 2, 4, 64, 64, playerIdolGh);

	backTitleGroundGh	= LoadGraph(fileName[(int)ImageDataIndex::backTitleImage]);
	backGroundGh		= LoadGraph(fileName[(int)ImageDataIndex::backGameImage]);
	backClearGroundGh	= LoadGraph(fileName[(int)ImageDataIndex::backClearImage]);
	titlelogoGh			= LoadGraph(fileName[(int)ImageDataIndex::titlelogoImage]);
	gameEffectGh		= LoadGraph(fileName[(int)ImageDataIndex::gameEffect]);
	gameEffectMoveGh	= LoadGraph(fileName[(int)ImageDataIndex::gameEffectMove]);
	clearLogoGh			= LoadGraph(fileName[(int)ImageDataIndex::clearLogo]);
}