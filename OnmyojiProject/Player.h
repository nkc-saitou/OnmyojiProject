#pragma once

#include "RectShape.h"

#include "PlayerCollision.h"
#include "SettingProvider.h"
#include "E_PlayerDirection.h"
#include "PlayerInput.h"

#include <memory>

namespace PlayerScope
{
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

		std::unique_ptr<PlayerCollision> playerCollision = std::make_unique<PlayerCollision>();
		std::unique_ptr<PlayerInput> plyaerInput = std::make_unique<PlayerInput>();

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

		int stageNum = 0;

		// 移動座標記憶
		double memoryX = x;
		double memoryY = y;

		// 座標
		double x, y;

		//移動しているかどうか 移動していたらtrue
		bool isMove = false;

		// 移動スピード
		double speed = 4.0;

		// 移動係数
		double move = 1.0;

		// まっすぐ進んでいるときの移動係数の値
		double straightMove = 1.0;

		// 斜めに進んでいるときの移動係数の値
		double tiltMove = 0.8;

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
		void Collision(Rect playerRect);
		// 表示処理
		void Draw();
		// 当たり判定の座標を登録
		void SetPosition();

	public:

		// スタート時のポジションをセット
		void SetStartPos(double posX, double posY);

		void Updata();

		// プレイヤーの向きを取得できる
		Direction GetPlayerDirection() { return directionState; }
	};
}