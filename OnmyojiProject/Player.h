#pragma once

#include "RectShape.h"
#include <memory>

/*
///////////////////////////////////////////
Direction列挙隊

概要　：移動方向の状態を管理する
///////////////////////////////////////////
*/
enum Direction
{
	up = 0,
	down,
	left,
	right
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
	// イメージのサイズ。縦横ともに64px
	const int graphSize = 64;

	// イメージ全体の分割数
	const int allDivision = 12;

	// 横の分割数
	const int divisionX = 3;

	// 縦の分割数
	const int divisionY = 4;


	// グラフィックハンドル
	int walkGh[12];
	int idolGh[8];

	// アナログスティックの回転度を取得
	int tempMoveX = 0, tempMoveY = 0;

	// 横方向と縦方向のカウント数
	int xCount = 0, yCount = 0;

	//添え時用変数
	int ix = 0, iy = 0, result = 0;


	// 座標
	double x = 360, y = 200;


	// 移動スピード
	float speed = 3.0f;

	// 移動係数
	float move = 1.0f;


	// 現在の方向
	Direction directionState = down;

	//===============================
	// 関数
	//===============================

	void Move(); // 移動処理
	void MoveGraphSet(); // 移動した際のイメージの変更処理
	void Collision(); // 当たり判定
	void Draw(); // 表示処理

public:
	Player();
	void SetPosition();
	void Update();
};