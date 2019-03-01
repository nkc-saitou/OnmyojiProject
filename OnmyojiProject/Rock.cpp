#include "Rock.h"
#include "DxLib.h"
#include "ImageLoader.h"
#include "StageInpoter.h"

void Rock::Move()
{

}


void Rock::Draw()
{
	DrawRotaGraph(x, y, 0.5, 0.0, ImageLoader::Instance()->GetGameStageGH()[chip_rock], TRUE);
}

void Rock::Collision()
{

}


void Rock::SetStartPos(double posX, double posY)
{
	x = posX * graphSize + (graphSize / 2);
	y = posY * graphSize + (graphSize / 2);
}


void Rock::Update()
{
	Draw();
}