#pragma once

#include "RectShape.h"
#include "RockCollision.h"
#include "E_PlayerDirection.h"

namespace RockScope {

	/*
	///////////////////////////////////////////
	Rockクラス

	概要　：石単体を制御するクラス
	///////////////////////////////////////////
	*/
	class Rock : public RectShape
	{

		std::unique_ptr<RockCollision> rockCollision = std::make_unique<RockCollision>();

		const int graphSize = 64;

		const int offset = 20;

		const double speed = 1.0;

		const double backMove = 2.0;


		double x = 0, y = 0;

		double memoryX = 0, memoryY = 0;

		bool isMove = false;

		bool isGoal = false;


		PlayerScope::Direction playerDir;


		void Draw();

		void Collision();

		void RectSet();

	public:
		// スタート時のポジションをセット
		void SetStartPos(double posX, double posY);

		void Move(PlayerScope::Direction dir);

		void Update();

		void IsMove(bool tempIsMove) { isMove = tempIsMove; }

		bool IsGoal() { return isGoal; }
	};
}