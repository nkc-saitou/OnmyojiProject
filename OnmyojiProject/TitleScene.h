#pragma once
#include "SettingProvider.h"

class TitleScene
{
	int screenX = 1300;
	int screenY = 300;

	int c = 0;

	bool isFade = true;

	void Draw();

public:

	void Uptate();
};