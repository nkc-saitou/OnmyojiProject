#include "StageDraw.h"
#include "DxLib.h"
#include "ImageLoader.h"

StageDraw::StageDraw(SceneState state)
{
	sceneState = state;
}


/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:ステージを描画
/////////////////////////////////////////////////////
void StageDraw::StillDraw()
{
	if (sceneState == SceneState::gameScene)
		DrawGraph(0, 0, ImageLoader::Instance()->GetBackGroundGH(), FALSE);
	else if(sceneState == SceneState::resultScene)
		DrawGraph(0, 0, ImageLoader::Instance()->GetBackClearGroundGh(), FALSE);

	for (int i = 0; i < stageHeight; i++)
	{
		for (int j = 0; j < stageWidth; j++)
		{
			if(sceneState == SceneState::gameScene)
				DrawExtendGraph(64 * j, 64 * i, (64 * j) + 64, (64 * i) + 64, ImageLoader::Instance()->GetGameStageGH()[stageData[i][j]], TRUE);
			else if (sceneState == SceneState::resultScene)
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