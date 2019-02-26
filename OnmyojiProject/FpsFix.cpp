#include "FpsFix.h"

void FpsFix::FpsCounter()
{
	// 1�t���[���ڂȂ玞�����L��
	if (count == 0) startTime = GetNowCount();

	// �U�O�t���[���ڂȂ畽�ς��v�Z����
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
	int tookTime = GetNowCount() - startTime;	//������������
	int waitTime = count * 1000 / fixFps - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}

void FpsFix::Updata()
{
	FpsCounter();
	DrawFormatString(0, 0, GetColor(255, 0, 0), "%.1f", fps);
	Wait();
}