#pragma once
#include <vector>
#include "StageInpoter.h"

class CreateGoalPoint
{
	const int graphSize = 64;

	int stageNum = 0;

	std::vector<position> goalPosData;

	void GoalPointRectSet();

public:

	void Init();
};