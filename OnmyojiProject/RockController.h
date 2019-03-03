#pragma once

#include <vector>
#include <memory>

#include "Rock.h"

class RockController
{
	std::vector<std::unique_ptr<Rock>> rock;

	int stageNum = 0;


	void Draw();

public:
	void Init(int num);

	void RockCollisonSet();

	void Update();


};