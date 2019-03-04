#include "Player.h"
#include "DxLib.h"
#include "Input.h"
#include "SettingProvider.h"
#include "StageInpoter.h"
#include "Collision.h"
#include "RectWatcher.h"

#include <cmath>

void Player::SetStageNumber()
{
	stageNum = SettingProvider::Instance()->GetStageNumber();
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:プレイヤーの移動
/////////////////////////////////////////////////////
void Player::Move()
{
	// 1920x1080
	const int screenSizeX = SettingProvider::Instance()->screenSizeX;
	const int screenSizeY = SettingProvider::Instance()->screenSizeY;

	// 絶対値に変換
	int moveX = abs(tempMoveX);
	int moveY = abs(tempMoveY);

	// 絶対値でどの方向の入力がされているのかを取得
	// まっすぐ移動していたら 1.0f ななめ移動していたら 0.71f
	if ((moveX >= 900 || moveY >= 900) && (moveX == 0 || moveY == 0)) move = straightMove;
	else if(moveX != 0 && moveY != 0) move = tiltMove;
	else move = straightMove;

	// 移動処理
	if (tempMoveX < 0) x -= (int)(speed * move);
	if (tempMoveX > 0) x += (int)(speed * move);
	if (tempMoveY < 0) y -= (int)(speed * move);
	if (tempMoveY > 0) y += (int)(speed * move);

	// ｘ方向、画面外に出ないように
	if (x + graphSize * 2 > screenSizeX) x = screenSizeX - graphSize * 2;
	if (x < graphSize) x = graphSize;
	// ｙ方向、画面外に出ないように
	if (y + graphSize * 2 > screenSizeY) y = screenSizeY - graphSize * 2;
	if (y < graphSize) y = graphSize;

	// 移動を止めた時は、idol状態の画像に変更する
	if (tempMoveX == 0 && tempMoveY == 0) isMove = false;
	else isMove = true;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:移動中のイメージ切り替え
/////////////////////////////////////////////////////
void Player::MoveGraphSet()
{
	// 左に移動している
	if (tempMoveX < 0)
	{
		directionState = leftDir;

		// xCountが０以上なら０にしてから１引く
		if (moveCountX > 0) moveCountX = 0;

		if(moveCountX < 40) --moveCountX;
		else moveCountX = 0;
	}
	// 右に移動している
	if (tempMoveX > 0)
	{
		directionState = rightDir;

		// xCountが０以下なら０にしてから１足す
		if (moveCountX < 0) moveCountX = 0;

		if(moveCountX > -40) ++moveCountX;
		else moveCountX = 0;
	}
	// 上に移動している
	if (tempMoveY < 0)
	{
		directionState = upDir;

		// yCountが０以上なら０にしてから１引く
		if (moveCountY > 0) moveCountY = 0;

		if(moveCountY < 40) --moveCountY;
		else moveCountY = 0;
	}
	// 下に移動している
	if (tempMoveY > 0)
	{
		directionState = downDir;

		// yCountが０以下なら０にしてから１足す
		if (moveCountY < 0) moveCountY = 0;

		if(moveCountY > -40) ++moveCountY;
		else moveCountY = 0;
	}

	// カウント数から添え字を求める
	tempMoveIndexX = abs(moveCountX) % 40 / 10;
	tempMoveIndexY = abs(moveCountY) % 40 / 10;


	// 斜め移動の場合は横顔を優先
	if (move == tiltMove)
	{
		if (tempMoveX < 0 && tempMoveY < 0)
		{
			directionState = upLeftDir;
		}
		if (tempMoveX < 0 && tempMoveY > 0)
		{
			directionState = downLeftDir;
		}
		if (tempMoveX > 0 && tempMoveY < 0)
		{
			directionState = upRightDir;
		}
		if (tempMoveX > 0 && tempMoveY > 0)
		{
			directionState = downRightDir;
		}

		moveIndex = tempMoveIndexX;
	}


	switch (directionState)
	{
	case upDir:
		// 下向きなので、２行目の先頭添え字配列を足す
		tempMoveIndexY += moveDivX;
		moveIndex = tempMoveIndexY;

		break;

	case downDir: 
		// 上向きなので、１行目の先頭添え字配列をresultに渡す
		moveIndex = tempMoveIndexY;

		break;

	case leftDir: 
		// 左向きなので、３行目の先頭添え字配列を足す
		tempMoveIndexX += moveDivX * leftDir;
		moveIndex = tempMoveIndexX;

		break;

	case rightDir: 
		// 右向きなので、４行目の先頭添え字番号を足す
		tempMoveIndexX += moveDivX * rightDir;
		moveIndex = tempMoveIndexX;

		break;

	case upLeftDir:
		// 左向きなので、３行目の先頭添え字配列を足す
		tempMoveIndexX += moveDivX * leftDir;
		moveIndex = tempMoveIndexX;

		break;

	case upRightDir:
		// 右向きなので、４行目の先頭添え字番号を足す
		tempMoveIndexX += moveDivX * rightDir;
		moveIndex = tempMoveIndexX;

		break;

	case downLeftDir:
		// 左向きなので、３行目の先頭添え字配列を足す
		tempMoveIndexX += moveDivX * leftDir;
		moveIndex = tempMoveIndexX;

		break;
		
	case downRightDir:
		// 右向きなので、４行目の先頭添え字番号を足す
		tempMoveIndexX += moveDivX * rightDir;
		moveIndex = tempMoveIndexX;

		break;
	}

	int t = directionState;

	//DrawFormatString(100, 100, GetColor(255, 0, 0), "direction : %d  x:%d y:%d", t, moveCountX, moveCountY);
	DrawFormatString(100, 100, GetColor(255, 0, 0), "direction : %i", collisionRect);
	// 移動していない場合は値を初期化
	if (tempMoveY == 0) moveCountY = 0;
	if (tempMoveX == 0) moveCountX = 0;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:待機中のイメージ切り替え
/////////////////////////////////////////////////////
void Player::IdolGraphSet()
{
	if (stopCount < 20) ++stopCount;
	else stopCount = 0;

	tempStopIndex = stopCount % 20 / 10;
	
	switch (directionState)
	{
	case downDir:		stopIndex = tempStopIndex;						break;
	case upDir:			stopIndex = tempStopIndex + stopDivX;			break;
	case leftDir:		stopIndex = tempStopIndex + stopDivX * leftDir;	break;
	case rightDir:		stopIndex = tempStopIndex + stopDivX * rightDir;break;
	case upLeftDir:		stopIndex = tempStopIndex + stopDivX * leftDir; break;
	case upRightDir:	stopIndex = tempStopIndex + stopDivX * rightDir; break;
	case downLeftDir:	stopIndex = tempStopIndex + stopDivX * leftDir; break;
	case downRightDir:	stopIndex = tempStopIndex + stopDivX * rightDir; break;
	}
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:当たり判定用の処理
/////////////////////////////////////////////////////
void Player::Collision(Rect playerRect)
{


	if (playerCollision->OnCollision(playerRect))
	{
		x = memoryX;
		y = memoryY;

		return;
	}

	memoryX = x;
	memoryY = y;
}


/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:描画
/////////////////////////////////////////////////////
void Player::Draw()
{

	MoveGraphSet();
	IdolGraphSet();

	// プレイヤー表示
	if(isMove) DrawGraph(x, y, ImageLoader::Instance()->GetPlayerWalkGH()[moveIndex], TRUE);
	else DrawGraph(x, y, ImageLoader::Instance()->GetPlayerIdolGH()[stopIndex], TRUE);
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:当たり判定の座標を登録
/////////////////////////////////////////////////////
void Player::SetPosition()
{
	double top	  =  y + 32;
	double bottom =  y + graphSize;
	double left   =  x + 20;
	double right  =  x + graphSize - 20;

	//DrawBox(left, top, right, bottom, GetColor(255, 0, 0), TRUE);

	SetValue(&top, &bottom, &left, &right);
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:スタート時のポジションをセット
/////////////////////////////////////////////////////
void Player::SetStartPos(double posX, double posY)
{
	x = posX * graphSize + (graphSize / 2);
	y = posY * graphSize + (graphSize / 2);
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:更新
/////////////////////////////////////////////////////
void Player::Updata()
{
	// アナログスティックの回転角度(-1000 ~ 1000)の取得
	tempMoveX = Input::Instance()->AngleInputX(Pad_1);
	tempMoveY = Input::Instance()->AngleInputY(Pad_1);


	//DrawFormatString(100, 600, GetColor(255, 255, 255), "top:%lf bottom:%lf left:%lf right:%lf", GetTop(), GetBottom(),GetLeft(),GetRight());

	Move();
	Draw();

	SetPosition();

	Rect rect = GetRect();

	//playerCollision->SetPlayerRect(rect);
	RectWatcher::Instance()->SetPlayerRect(rect);
	Collision(rect);
}