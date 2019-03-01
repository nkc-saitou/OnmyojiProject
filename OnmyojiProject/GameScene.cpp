#include "GameScene.h"
#include "SettingProvider.h"
#include "DxLib.h"

/////////////////////////////////////////////////////
//引数			:ステージ数
//戻り値		:なし
//動作			:ステージデータをstageDrawに送る
/////////////////////////////////////////////////////
void GameScene::SetStageNum(int num)
{
	// ステージの総数より大きな数字が与えられないように設定
	if (MaxStageNum > num) stageNum = num;

	SettingProvider::Instance()->SetStageNumber(num);

	player->SetStageNumber(num);

	// StageDrawにステージデータを渡す
	stageDraw->SetStageData(StageInpoter::Instance()->GetStageData()[num]);

	// プレイヤーの初期位置を取得
	position pos = StageInpoter::Instance()->GetPlayerPosData()[num];
	player->SetStartPos(pos.x, pos.y);


	vector<position> rockPos = StageInpoter::Instance()->GetRockPosData()[num];

	for (int i = 0; i < rockPos.size(); i++)
	{
		rock.emplace_back(make_unique<Rock>());
		rock[i]->SetStartPos(rockPos[i].x, rockPos[i].y);
	}

	// テスト描画用。
	testVec = StageInpoter::Instance()->GetCollisionData()[num];
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:描画
/////////////////////////////////////////////////////
void GameScene::Draw()
{
	//for (int i = 0; i < testVec.size(); i++)
	//{
		//int x = testVec[i].x;
		//int y = testVec[i].y;
		////DrawCircle(32 + x * 64,32 + y * 64, 5, GetColor(255, 0, 0), TRUE);

		//int top = y * 64;
		//int left = x * 64;
		//int bottom = top + 64;
		//int right = left + 64;

		//DrawBox(left, top, right, bottom, GetColor(255, 0, 0), TRUE);
	//}
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:更新
/////////////////////////////////////////////////////
void GameScene::Update()
{
	stageDraw->Update();

	for (int i = 0; i < rock.size(); i++) rock[i]->Update();
	

	//Draw();
	player->Updata();

}