#include "RockController.h"

#include "StageInpoter.h"
#include "Input.h"
#include "SettingProvider.h"
#include "CollisionRectProvider.h"
#include "PlayerProvider.h"

namespace RockScope
{
	using namespace std;
	using namespace PlayerScope;

	void RockController::RockStartPosSet(int stageNum)
	{
		std::vector<position> rockPos = StageInpoter::Instance()->GetRockPosData()[stageNum];

		for (int i = 0; i < rockPos.size(); i++)
		{
			rock.emplace_back(make_unique<Rock>());
			rock[i]->SetStartPos(rockPos[i].x, rockPos[i].y);
		}
	}


	void RockController::RockCollisonSet()
	{
		vector<Rect> tempRect;
		for (int i = 0; i < rock.size(); i++)
		{
			tempRect.push_back(rock[i]->GetRect());
		}

		CollisionRectProvider::Instance()->SetRockRect(tempRect);
	}


	void RockController::Update()
	{
		playerInput->Update();



		if (playerInput->GetIsAction())
		{
			dir = PlayerProvider::Instance()->GetPlayerDirection();
			for (int i = 0; i < rock.size(); i++) rock[i]->IsMove(true);
		}


		for (int i = 0; i < rock.size(); i++)
		{
			rock[i]->Update();
			rock[i]->Move(dir);
		}


		RockCollisonSet();
	}

}