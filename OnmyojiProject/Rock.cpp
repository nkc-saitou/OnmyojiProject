#include "Rock.h"
#include "DxLib.h"
#include "ImageLoader.h"
#include "StageInpoter.h"

void Rock::Move()
{

}


void Rock::Draw()
{
	DrawExtendGraph(x, y, x + graphSize, y + graphSize, ImageLoader::Instance()->GetGameStageGH()[chip_rock], TRUE);
}


void Rock::Collision()
{

}


void Rock::RectSet()
{
	double top	  =  y + 15;
	double bottom =  y + graphSize - 15;
	double left   =  x + 15;
	double right  =  x + graphSize - 15;

	//DrawBox(left, top, right, bottom, GetColor(255, 0, 0), TRUE);

	SetValue(&top, &bottom, &left, &right);
}


void Rock::SetStartPos(double posX, double posY)
{
	x = posX * graphSize;
	y = posY * graphSize;
}


void Rock::Update()
{
	Draw();
	RectSet();
}