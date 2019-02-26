#include "GameScene.h"

GameScene::GameScene(int num)
{
	if (MaxStageNum > num) stageNum = num;

	stageDraw->SetStageData(StageInpoter::Instance()->GetStageData()[num]);
}

void GameScene::Draw()
{
	
}

void GameScene::Update()
{
	stageDraw->Update();
	player->Updata();
}