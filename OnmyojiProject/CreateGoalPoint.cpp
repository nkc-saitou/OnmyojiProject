#include "CreateGoalPoint.h"
#include "SettingProvider.h"
#include "S_Rect.h"
#include "CollisionRectProvider.h"

void CreateGoalPoint::Init()
{
	stageNum = SettingProvider::Instance()->GetStageNumber();

	goalPosData = StageInpoter::Instance()->GetStarPosData()[stageNum];

	GoalPointRectSet();
}

void CreateGoalPoint::GoalPointRectSet()
{
	std::vector<Rect> goalPosRectData;

	for (position goalPos : goalPosData)
	{
		Rect tempGoalPos;

		tempGoalPos.top		= goalPos.y * graphSize + (graphSize / 3);
		tempGoalPos.bottom	= goalPos.y * graphSize + graphSize - (graphSize / 3);
		tempGoalPos.left	= goalPos.x * graphSize + (graphSize / 3);
		tempGoalPos.right	= goalPos.x * graphSize + graphSize - (graphSize / 3);

		goalPosRectData.push_back(tempGoalPos);
	}

	CollisionRectProvider::Instance()->SetGoalRect(goalPosRectData);
}