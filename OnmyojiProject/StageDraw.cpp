#include "StageDraw.h"
#include "DxLib.h"
#include "ImageLoader.h"

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:ステージを描画
/////////////////////////////////////////////////////
void StageDraw::StillDraw()
{
	DrawGraph(0, 0, ImageLoader::Instance()->GetBackGroundGH(), FALSE);

	for (int i = 0; i < stageHeight; i++)
	{
		for (int j = 0; j < stageWidth; j++)
		{
			DrawExtendGraph(64 * j, 64 * i, (64 * j) + 64, (64 * i) + 64, ImageLoader::Instance()->GetGameStageGH()[stageData[i][j]], TRUE);
		}
	}
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:描画
/////////////////////////////////////////////////////
void StageDraw::Draw()
{
	StillDraw();
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:更新
/////////////////////////////////////////////////////
void StageDraw::Update()
{
	Draw();
}