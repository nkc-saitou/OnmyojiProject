#pragma once

#include <math.h>
#include "DxLib.h"
#include "Singleton.h"

class FpsFix : public Singleton <FpsFix>
{
	//測定開始時刻
	int startTime = 0;
	// カウンター
	int count = 0;
	// fps
	float fps = 0;

	// 固定のfps
	static const int fixFps = 60;
	// 平均のfps
	static const int averageFps = 60;

	// 毎フレーム更新
	void FpsCounter();

	// 固定Fpsで待機する
	void Wait();

public:
	// Fps描画
	void Updata();
};