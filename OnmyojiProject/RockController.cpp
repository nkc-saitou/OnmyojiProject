#include "RockController.h"
#include "StageInpoter.h"

void RockController::Init(int num)
{
	stageNum = num;

	std::vector<position> rockPos = StageInpoter::Instance()->GetRockPosData()[num];

	for (int i = 0; i < rockPos.size(); i++)
	{
		rock.emplace_back(make_unique<Rock>());
		rock[i]->SetStartPos(rockPos[i].x, rockPos[i].y);
	}
}


void RockController::Draw()
{

}


void RockController::RockCollisonSet()
{

}


void RockController::Update()
{
	for (int i = 0; i < rock.size(); i++) rock[i]->Update();
}