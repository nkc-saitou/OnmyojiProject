#pragma once

#include "RectShape.h"
#include "ImageLoader.h"
#include "PlayerCollision.h"
#include "SettingProvider.h"

#include <memory>

/*
///////////////////////////////////////////
Direction列挙隊

概要　：移動方向の状態を管理する
///////////////////////////////////////////
*/
enum Direction
{
	upDir = 0,
	downDir,
	leftDir,
	rightDir
};

/*
///////////////////////////////////////////
Playerクラス

概要　：プレイヤーの表示、挙動を制御
///////////////////////////////////////////
*/
class  Player : public RectShape
{
	//===============================
	// 変数
	//===============================

private:

	unique_ptr<PlayerCollision> playerCollision = make_unique<PlayerCollision>();

	// イメージのサイズ。縦横ともに64px
	const int graphSize = 64;

	// 移動しているときの横の分割数
	const int moveDivX = 4;

	// 止まっているときの横の分割数
	const int stopDivX = 2;

	// アナログスティックの回転度を取得
	int tempMoveX = 0, tempMoveY = 0;

	// 横方向と縦方向のカウント数
	int moveCountX = 0, moveCountY = 0;

	// 待機
	int stopCount = 0, tempStopIndex = 0, stopIndex = 0;

	//添え時用変数
	int tempMoveIndexX = 0, tempMoveIndexY = 0, moveIndex = 0;

	int stageNum = SettingProvider::Instance()->GetStageNumber();

	int memoryX = x;
	int memoryY = y;

	// 座標
	double x, y;

	//移動しているかどうか 移動していたらtrue
	bool isMove = false;


	// 移動スピード
	double speed = 3.0;

	// 移動係数
	double move = 1.0;

	// まっすぐ進んでいるときの移動係数の値
	double straightMove = 1.0;

	// 斜めに進んでいるときの移動係数の値
	double tiltMove = 0.71;

	// 現在の方向
	Direction directionState = downDir;

	//===============================
	// 関数
	//===============================

	// 移動処理
	void Move();
	// 移動した際のイメージの変更処理
	void MoveGraphSet();
	// 待機状態のイメージ変更処理
	void IdolGraphSet();
	// 当たり判定
	void Collision();
	// 表示処理
	void Draw(); 
	// 当たり判定の座標を登録
	void SetPosition();

public:

	Player();

	// スタート時のポジションをセット
	void SetStartPos(double posX,double posY);

	void Updata();
};