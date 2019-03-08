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

	/////////////////////////////////////////////////////
	//引数			:ステージ番号
	//戻り値		:なし
	//動作			:岩の初期位置を設定
	/////////////////////////////////////////////////////
	void RockController::RockStartPosSet(int stageNum)
	{
		std::vector<position> rockPos = StageInpoter::Instance()->GetRockPosData()[stageNum];

		for (int i = 0; i < rockPos.size(); i++)
		{
			rock.emplace_back(make_unique<Rock>());
			rock[i]->SetStartPos(rockPos[i].x, rockPos[i].y);
		}
	}

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:岩の当たり判定をセット
	/////////////////////////////////////////////////////
	void RockController::RockCollisonSet()
	{
		vector<Rect> tempRect;

		for (int i = 0; i < rock.size(); i++)
		{
			if(rock[i]->IsGoal() != true) tempRect.push_back(rock[i]->GetRect());
		}

		// 当たり判定を代入
		CollisionRectProvider::Instance()->SetRockRect(tempRect);
	}

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:更新
	/////////////////////////////////////////////////////
	void RockController::Update()
	{
		// プレイヤーの入力を更新
		playerInput->Update();

		// アクションボタンが押されていたら
		if (playerInput->GetIsAction())
		{
			// プレイヤーの向きを保存
			dir = PlayerProvider::Instance()->GetPlayerDirection();

			// 岩を動かす
			for (int i = 0; i < rock.size(); i++) rock[i]->IsMove(true);
		}

		// 岩それぞれを更新
		for (int i = 0; i < rock.size(); i++)
		{
			rock[i]->Update();
			// 岩をプレイヤーの向きに動かす
			rock[i]->Move(dir);
		}


		RockCollisonSet();
	}

}