#pragma once
#include "Singleton.h"
#include "E_SceneState.h"

class FadeManager : public Singleton <FadeManager>
{

	int c = 0;
public:

	bool IsWhiteFadeIn();
	bool IsWhiteFadeOut();

	void ResetFadeValue();
};