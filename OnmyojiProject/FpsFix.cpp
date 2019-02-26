#include "FpsFix.h"

void FpsFix::FpsCounter()
{
	// 1フレーム目なら時刻を記憶
	if (count == 0) startTime = GetNowCount();

	// ６０フレーム目なら平均を計算する
	if (count == averageFps)
	{
		int tempTime = GetNowCount();
		fps = 1000.f / ((tempTime - startTime) / (float)averageFps);
		count = 0;
		startTime = tempTime;
	}

	count++;
}

void FpsFix::Wait()
{
	int tookTime = GetNowCount() - startTime;	//かかった時間
	int waitTime = count * 1000 / fixFps - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}

void FpsFix::Updata()
{
	FpsCounter();
	DrawFormatString(0, 0, GetColor(255, 0, 0), "%.1f", fps);
	Wait();
}