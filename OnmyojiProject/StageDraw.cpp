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
			DrawRotaGraph(32 + 64 * j, 32 + 64 * i, 0.5, 0.0, ImageLoader::Instance()->GetGameStageGH()[stageData[i][j]], TRUE);
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