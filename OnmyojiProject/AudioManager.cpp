#include "AudioManager.h"
#include "DxLib.h"

void AudioManager::LoadSound()
{
	b_titleSh = LoadSoundMem(fileBGMName[titleBGM]);
	b_gameSh = LoadSoundMem(fileBGMName[gameBGM]);
	b_resultSh = LoadSoundMem(fileBGMName[resultBGM]);

	s_playerWalkSh = LoadSoundMem(fileSEName[walkSE]);
}

void AudioManager::PlayBGM(int sh, int volume)
{
	ChangeVolumeSoundMem(volume, sh);

	if (CheckSoundMem(bgmMemorySh) == 1)
	{
		StopSoundMem(bgmMemorySh);
	}

	PlaySoundMem(sh, DX_PLAYTYPE_LOOP, TRUE);
	bgmMemorySh = sh;
}

void AudioManager::PlaySE(int sh, int volume)
{
	PlaySoundMem(sh, DX_PLAYTYPE_BACK, TRUE);
}