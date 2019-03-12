#include "GameScene.h"
#include "SettingProvider.h"
#include "CollisionRectProvider.h"
#include "E_SceneState.h"
#include "Input.h"

#include "FadeManager.h"
#include "ImageLoader.h"
#include "DxLib.h"

/////////////////////////////////////////////////////
//引数			:ステージ番号
//戻り値		:なし
//動作			:ステージデータをstageDrawに送る
/////////////////////////////////////////////////////
void GameScene::SetStage(int num)
{
	// ステージの総数より大きな数字が与えられないように設定
	if (MaxStageNum > num) stageNum = num;


	stageDraw = std::make_unique<StageDraw>(SceneState::gameScene);
	player = std::make_unique<PlayerScope::Player>();
	stageCollision = std::make_unique<StageCollision>();
	rockController = std::make_unique<RockScope::RockController>();
	createGoalPoint = std::make_unique<CreateGoalPoint>();

	SettingProvider::Instance()->SetClearFlg(false);

	// ステージ番号を記録させておく
	SettingProvider::Instance()->SetStageNumber(stageNum);

	// StageDrawにステージデータを渡す
	stageDraw->SetStageData(StageInpoter::Instance()->GetStageData()[stageNum]);

	// ステージの当たり判定を設定する
	stageCollision->SetCollsionPosition();

	// ゴールの位置をセット
	createGoalPoint->Init();

	// プレイヤーの初期位置を取得
	position pos = StageInpoter::Instance()->GetPlayerPosData()[stageNum];
	player->SetStartPos(pos.x, pos.y);

	// rockControllerの初期位置をセットする
	rockController->RockStartPosSet(stageNum);

	// テスト描画用
	testVec = CollisionRectProvider::Instance()->GetStageRect();


	isTest = false;
}

void GameScene::GameClear()
{
	if (CollisionRectProvider::Instance()->GetGoalRect().size() == 0 || isTest == true)
	{
		if (FadeManager::Instance()->IsWhiteFadeIn())
		{
			SettingProvider::Instance()->SetClearFlg(true);
			SettingProvider::Instance()->SetSceneState(SceneState::resultScene);
		}

	}
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:描画
/////////////////////////////////////////////////////
void GameScene::Draw()
{
	for (int i = 0; i < testVec.size(); i++)
	{
		DrawBox(testVec[i].left, testVec[i].top, testVec[i].right, testVec[i].bottom, GetColor(255, 0, 0), TRUE);
	}

	Rect top = CollisionRectProvider::Instance()->GetTopEdgeStageRect();
	Rect bottom = CollisionRectProvider::Instance()->GetBottomEdgeStageRect();
	Rect left = CollisionRectProvider::Instance()->GetLeftEdgeStageRect();
	Rect right = CollisionRectProvider::Instance()->GetRightEdgeStageRect();

	DrawBox(top.left, top.top, top.right, top.bottom, GetColor(255, 0, 0), TRUE);
	DrawBox(bottom.left, bottom.top, bottom.right, bottom.bottom, GetColor(255, 0, 0), TRUE);
	DrawBox(left.left, left.top, left.right, left.bottom, GetColor(255, 0, 0), TRUE);
	DrawBox(right.left, right.top, right.right, right.bottom, GetColor(255, 0, 0), TRUE);
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:更新
/////////////////////////////////////////////////////
void GameScene::Update()
{
	if (Input::Instance()->ButtonDown(XINPUT_BUTTON_Y,Pad_1) || Input::Instance()->ButtonDown(KEY_INPUT_X))
		SettingProvider::Instance()->SetSceneState(SceneState::titleScene);

	if (Input::Instance()->ButtonDown(KEY_INPUT_T)) isTest = true;

	stageDraw->Update();

	player->Updata();

	rockController->Update();


	// 展示会用　終わったら消す
	DrawGraph(0, 0, ImageLoader::Instance()->GetGameEffectGh(), TRUE);

	DrawGraph(oneEffect, 0, ImageLoader::Instance()->GetGameEffectMoveGh(), TRUE);
	DrawGraph(twoEffect, 0, ImageLoader::Instance()->GetGameEffectMoveGh(), TRUE);

	oneEffect = (oneEffect > -1920) ? (oneEffect - 1) : 1920;
	twoEffect = (twoEffect > -1920) ? (twoEffect - 1) : 1920;




	GameClear();


	//Draw();
}