#include "FadeManager.h"
#include "DxLib.h"
#include "SettingProvider.h"

bool FadeManager::IsWhiteFadeIn()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, c);
	DrawBox(0, 0, 1920, 1080, GetColor(255, 255, 255), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	c++;

	if (c > 254)
	{
		return true;
	}
	else return false;


}

bool FadeManager::IsWhiteFadeOut()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, c);
	DrawBox(0, 0, 1920, 1080, GetColor(255, 255, 255), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	c--;

	if (c < 0)
	{
		c = -1;
		return true;
	}

	return false;
}

void FadeManager::ResetFadeValue()
{
	c = 0;
}