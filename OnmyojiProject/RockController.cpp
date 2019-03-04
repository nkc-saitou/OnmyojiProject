#include "RockController.h"
#include "StageInpoter.h"
#include "SettingProvider.h"
#include "RectWatcher.h"

void RockController::Init(int num)
{
	stageNum = SettingProvider::Instance()->GetStageNumber();

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
	vector<Rect> tempRect;
	for (int i = 0; i < rock.size(); i++)
	{
		tempRect.push_back(rock[i]->GetRect());
	}

	RectWatcher::Instance()->SetRockRect(tempRect);
}


void RockController::Update()
{
	for (int i = 0; i < rock.size(); i++) rock[i]->Update();
	RockCollisonSet();
}