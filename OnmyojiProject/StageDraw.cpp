#include "StageDraw.h"
#include "DxLib.h"
#include "ImageLoader.h"

void StageDraw::StillDraw()
{
	DrawGraph(0, 0, ImageLoader::Instance()->BackGroundGH(), FALSE);

	for (int i = 0; i < stageHeight; i++)
	{
		for (int j = 0; j < stageWidth; j++)
		{
			DrawRotaGraph(32 + 64 * j, 32 + 64 * i, 0.5, 0.0, ImageLoader::Instance()->GameStageGH()[stageData[i][j]], TRUE);
		}
	}
}

void StageDraw::Draw()
{
	StillDraw();
}

void StageDraw::SetStageData(vector<vector<int>> data)
{
	stageData = data;
}

void StageDraw::Update()
{
	Draw();
}