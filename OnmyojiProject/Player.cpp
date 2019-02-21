#include "Player.h"
#include "DxLib.h"
#include "Input.h"

#include <cmath>

Player::Player() : RectShape()
{
	// 画像読み込み
	LoadDivGraph("test.png", allDivision, divisionX, divisionY, graphSize, graphSize, walkGh);
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:プレイヤーの移動
/////////////////////////////////////////////////////
void Player::Move()
{
	// 絶対値に変換
	int moveX = abs(tempMoveX);
	int moveY = abs(tempMoveY);

	// 絶対値でどの方向の入力がされているのかを取得
	// まっすぐ移動していたら 1.0f ななめ移動していたら 0.71f
	if ((moveX == 1000 || moveY == 1000) && (moveX == 0 || moveY == 0)) move = 1.0f;
	else if(moveX != 0) move = 0.71f;

	// 移動処理
	if (tempMoveX < 0) x -= (int)(speed * move);
	if (tempMoveX > 0) x += (int)(speed * move);
	if (tempMoveY < 0) y -= (int)(speed * move);
	if (tempMoveY > 0) y += (int)(speed * move);

	// ｘ方向、画面外に出ないように
	if (x + 64 > 1600) x = 1600 - 64;
	if (x < 64) x = 64;
	// ｙ方向、画面外に出ないように
	if (y + 64 > 900) y = 900 -64;
	if (y < 64) y = 64;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:プレイヤーのイメージ切り替え
/////////////////////////////////////////////////////
void Player::MoveGraphSet()
{
	// 左に移動している
	if (tempMoveX < 0)
	{
		directionState = left;

		// xCountが０以上なら０にしてから１引く
		if (xCount > 0) xCount = 0;

		if(xCount < 30) --xCount;
		else xCount = 0;
	}
	// 右に移動している
	if (tempMoveX > 0)
	{
		directionState = right;

		// xCountが０以下なら０にしてから１足す
		if (xCount < 0) xCount = 0;

		if(xCount > -30) ++xCount;
		else xCount = 0;
	}
	// 上に移動している
	if (tempMoveY < 0)
	{
		directionState = up;

		// yCountが０以上なら０にしてから１引く
		if (yCount > 0) yCount = 0;

		if(yCount < 30) --yCount;
		else yCount = 0;
	}
	// 下に移動している
	if (tempMoveY > 0)
	{
		directionState = down;

		// yCountが０以下なら０にしてから１足す
		if (yCount < 0) yCount = 0;

		if(yCount > -30) ++yCount;
		else yCount = 0;
	}

	// カウント数から添え字を求める
	ix = abs(xCount) % 30 / 10;
	iy = abs(yCount) % 30 / 10;

	// 右を向いている
	if (xCount > 0)
	{
		// 右向きなので、３行目の先頭添え字番号を足す
		ix += divisionX * 2;
		result = ix;
	}
	// 左を向いている
	else if (xCount < 0)
	{
		// 左向きなので、２行目の先頭添え字配列を足す
		ix += divisionX;
		result = ix;
	}

	// 下を向いている
	if (yCount < 0)
	{
		// 下向きなので、４行目の先頭添え字配列を足す
		iy += divisionX * 3;
		result = iy;
	}
	// 上を向いている
	else if (yCount > 0)
	{
		result = iy;
	}

	// 斜め移動の場合は横顔を優先
	if (move == 0.71f) result = ix;

	// 移動していない場合は値を初期化
	if (tempMoveY == 0) yCount = 0;
	if (tempMoveX == 0) xCount = 0;

	// 移動を止めた時は、止まる前まで向いていた方向の絵の先頭を表示する
	if (tempMoveX == 0 && tempMoveY == 0)
	{
		switch (directionState)
		{
		case down:	result = 0;				break;
		case left:	result = divisionX;		break;
		case right:	result = divisionX * 2; break;
		case up:	result = divisionX * 3; break;
		}
	}
}

void Player::Collision()
{

}


/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:描画
/////////////////////////////////////////////////////
void Player::Draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "x:%lf y:%lf",x, y);

	MoveGraphSet();

	// プレイヤー表示
	DrawGraph(x, y, walkGh[result], TRUE);
	DrawCircle(x, y, 10, GetColor(255, 0, 0), TRUE);

}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:当たり判定の座標を登録
/////////////////////////////////////////////////////
void Player::SetPosition()
{
	double top	  =  y;
	double bottom =  y + graphSize;
	double left   =  x;
	double right  =  x + graphSize;

	SetValue(&top, &bottom, &left, &right);
}


/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:更新
/////////////////////////////////////////////////////
void Player::Update()
{
	// アナログスティックの回転角度(-1000 ~ 1000)の取得
	tempMoveX = Input::Instance()->AngleInputX(Pad_1);
	tempMoveY = Input::Instance()->AngleInputY(Pad_1);


	DrawFormatString(100, 600, GetColor(255, 255, 255), "top:%lf bottom:%lf left:%lf right:%lf", GetTop(), GetBottom(),GetLeft(),GetRight());

	Move();
	Draw();
	SetPosition();
}