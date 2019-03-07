#pragma once

namespace PlayerScope
{
/*
///////////////////////////////////////////
Direction列挙隊

概要　：移動方向の状態を管理する
///////////////////////////////////////////
*/
	enum class Direction
	{
		upDir = 0,
		downDir,
		leftDir,
		rightDir,
		upLeftDir,
		downLeftDir,
		upRightDir,
		downRightDir
	};
}