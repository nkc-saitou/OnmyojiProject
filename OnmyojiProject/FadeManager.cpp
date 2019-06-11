#include "FadeManager.h"
#include "DxLib.h"
#include "SettingProvider.h"

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:フェードが終わっているかどうか
//動作			:フェードイン
/////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:フェードが終わっているかどうか
//動作			:フェードアウト
/////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:フェード値の初期化
/////////////////////////////////////////////////////
void FadeManager::ResetFadeValue()
{
	c = 0;
}