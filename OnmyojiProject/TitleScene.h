#pragma once
#include "SettingProvider.h"

class TitleScene
{
	int screenX = SettingProvider::Instance()->screenSizeX / 5;
	int screenY = SettingProvider::Instance()->screenSizeY / 3;

	void Draw();

public:
	void Uptate();
};