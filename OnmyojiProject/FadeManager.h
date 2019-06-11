#pragma once
#include "Singleton.h"
#include "E_SceneState.h"

/*
///////////////////////////////////////////
FadeManagerクラス

概要　：フェードインアウトを制御するクラス
///////////////////////////////////////////
*/
class FadeManager : public Singleton <FadeManager>
{

	int c = 0;
public:

	bool IsWhiteFadeIn();
	bool IsWhiteFadeOut();

	void ResetFadeValue();
};