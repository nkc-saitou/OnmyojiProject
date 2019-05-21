#include "Player.h"

#include "DxLib.h"

#include "Collision.h"
#include "StageInpoter.h"
#include "ImageLoader.h"
#include "SettingProvider.h"
#include "CollisionRectProvider.h"
#include "PlayerProvider.h"

#include <cmath>

namespace PlayerScope
{
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
		else if (moveX != 0 && moveY != 0) move = tiltMove;
		else move = straightMove;

		// 移動処理
		if (tempMoveX < 0) x -= (int)(speed * move);
		if (tempMoveX > 0) x += (int)(speed * move);
		if (tempMoveY < 0) y -= (int)(speed * move);
		if (tempMoveY > 0) y += (int)(speed * move);

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
			directionState = Direction::leftDir;

			// xCountが０以上なら０にしてから１引く
			if (moveCountX > 0) moveCountX = 0;

			if (moveCountX < 40) --moveCountX;
			else moveCountX = 0;
		}
		// 右に移動している
		if (tempMoveX > 0)
		{
			directionState = Direction::rightDir;

			// xCountが０以下なら０にしてから１足す
			if (moveCountX < 0) moveCountX = 0;

			if (moveCountX > -40) ++moveCountX;
			else moveCountX = 0;
		}
		// 上に移動している
		if (tempMoveY < 0)
		{
			directionState = Direction::upDir;

			// yCountが０以上なら０にしてから１引く
			if (moveCountY > 0) moveCountY = 0;

			if (moveCountY < 40) --moveCountY;
			else moveCountY = 0;
		}
		// 下に移動している
		if (tempMoveY > 0)
		{
			directionState = Direction::downDir;

			// yCountが０以下なら０にしてから１足す
			if (moveCountY < 0) moveCountY = 0;

			if (moveCountY > -40) ++moveCountY;
			else moveCountY = 0;
		}

		// カウント数から添え字を求める
		tempMoveIndexX = abs(moveCountX) % 40 / 10;
		tempMoveIndexY = abs(moveCountY) % 40 / 10;


		// 斜めに移動しているかどうかを調べ、移動方向を設定する
		if (move == tiltMove)
		{
			if (tempMoveX < 0 && tempMoveY < 0)
			{
				directionState = Direction::upLeftDir;
			}
			else if (tempMoveX < 0 && tempMoveY > 0)
			{
				directionState = Direction::downLeftDir;
			}
			else if (tempMoveX > 0 && tempMoveY < 0)
			{
				directionState = Direction::upRightDir;
			}
			else if (tempMoveX > 0 && tempMoveY > 0)
			{
				directionState = Direction::downRightDir;
			}

			moveIndex = tempMoveIndexX;
		}


		switch (directionState)
		{

			//========== 正面方向 ==========

		case Direction::upDir:
			// 上向き(後ろ姿)なので、２行目の先頭添え字配列を足す
			tempMoveIndexY += moveDivX;
			moveIndex = tempMoveIndexY;

			break;

		case Direction::downDir:
			// 下向き(正面姿)なので、１行目の先頭添え字配列をresultに渡す
			moveIndex = tempMoveIndexY;

			break;

		case Direction::leftDir:
			// 左向きなので、３行目の先頭添え字配列を足す
			tempMoveIndexX += moveDivX * (int)Direction::leftDir;
			moveIndex = tempMoveIndexX;

			break;

		case Direction::rightDir:
			// 右向きなので、４行目の先頭添え字番号を足す
			tempMoveIndexX += moveDivX * (int)Direction::rightDir;
			moveIndex = tempMoveIndexX;

			break;

			//========== 斜め方向 ==========

		case Direction::upLeftDir:
			tempMoveIndexX += moveDivX * (int)Direction::leftDir;
			moveIndex = tempMoveIndexX;

			break;

		case Direction::upRightDir:
			tempMoveIndexX += moveDivX * (int)Direction::rightDir;
			moveIndex = tempMoveIndexX;

			break;

		case Direction::downLeftDir:
			tempMoveIndexX += moveDivX * (int)Direction::leftDir;
			moveIndex = tempMoveIndexX;

			break;

		case Direction::downRightDir:
			tempMoveIndexX += moveDivX * (int)Direction::rightDir;
			moveIndex = tempMoveIndexX;

			break;
		}

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
		case Direction::upDir:			stopIndex = tempStopIndex + stopDivX;								break;
		case Direction::downDir:		stopIndex = tempStopIndex;											break;
		case Direction::leftDir:		stopIndex = tempStopIndex + stopDivX * (int)Direction::leftDir;		break;
		case Direction::rightDir:		stopIndex = tempStopIndex + stopDivX * (int)Direction::rightDir;	break;
		case Direction::upLeftDir:		stopIndex = tempStopIndex + stopDivX * (int)Direction::leftDir;		break;
		case Direction::upRightDir:		stopIndex = tempStopIndex + stopDivX * (int)Direction::rightDir;	break;
		case Direction::downLeftDir:	stopIndex = tempStopIndex + stopDivX * (int)Direction::leftDir;		break;
		case Direction::downRightDir:	stopIndex = tempStopIndex + stopDivX * (int)Direction::rightDir;	break;
		}
	}

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:当たり判定用の処理
	/////////////////////////////////////////////////////
	void Player::Collision()
	{
		if (playerCollision->OnCollision(x, y))
		{
			// 食い込まないように位置を戻す
			x = memoryX;
			y = memoryY;

			return;
		}

		// 衝突前の位置を記録しておく
		memoryX = x;
		memoryY = y;
	}

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:描画用のデータを登録
	/////////////////////////////////////////////////////
	void Player::SetLayerData()
	{
		if (isMove) rendererData.gh = ImageLoader::Instance()->GetPlayerWalkGH()[moveIndex];
		else rendererData.gh = ImageLoader::Instance()->GetPlayerIdolGH()[stopIndex];

		rendererData.x = x;
		rendererData.y = y;
		rendererData.orderInLayer = 0;
		rendererData.layerType = LayerType::object;
		rendererData.TransparencySortFlg = TRUE;
		rendererData.transFlg = TRUE;
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

		SetLayerData();

		//// プレイヤー表示
		//if (isMove) DrawGraph(x, y, ImageLoader::Instance()->GetPlayerWalkGH()[moveIndex], TRUE);
		//else DrawGraph(x, y, ImageLoader::Instance()->GetPlayerIdolGH()[stopIndex], TRUE);
	}

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:当たり判定の座標を登録
	/////////////////////////////////////////////////////
	void Player::SetPosition()
	{
		// 当たり判定を付ける範囲を設定しておく
		double top = y + collisionOffset;
		double bottom = y + graphSize;
		double left = x + collisionOffset;
		double right = x + graphSize - collisionOffset;

		// 値を保存
		SetValue(&top, &bottom, &left, &right);
	}

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:スタート時のポジションをセット
	/////////////////////////////////////////////////////
	void Player::SetStartPos(double posX, double posY)
	{
		x = posX * graphSize;
		y = posY * graphSize;
	}

	/////////////////////////////////////////////////////
	//引数			:なし
	//戻り値		:なし
	//動作			:更新
	/////////////////////////////////////////////////////
	void Player::Updata()
	{
		// アナログスティックの回転角度(-1000 ~ 1000)の取得
		tempMoveX = plyaerInput->GetMoveAngleX();
		tempMoveY = plyaerInput->GetMoveAngleY();

		// プレイヤー入力を更新
		plyaerInput->Update();

		// プレイヤーの向きを記憶しておく
		PlayerProvider::Instance()->SetPlayerDirection(directionState);

		// プレイヤーの座標を記憶しておく
		PlayerProvider::Instance()->SetPlayerPosX(x);
		PlayerProvider::Instance()->SetPlayerPosY(y);

		// 常にCollisionRectProviderでPlayerのRectを監視する
		Rect rect = GetRect();
		CollisionRectProvider::Instance()->SetPlayerRect(rect);

		if (SettingProvider::Instance()->GetIsClear() == false)
		{
			// 当たり判定
			Collision();

			Move();

			SetPosition();
		}

		Draw();

	}

}