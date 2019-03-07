#pragma once
#include "Singleton.h"
#include "E_PlayerDirection.h"

/*
///////////////////////////////////////////
PlayerProviderクラス

概要　：プレイヤーの座標や向きを取得できる
///////////////////////////////////////////
*/
class PlayerProvider : public Singleton <PlayerProvider>
{
	double x;
	double y;

	PlayerScope::Direction dir;

public:
	void SetPlayerPosX(double posX) { x = posX; }
	double GetPlayerPosX() { return x; }

	void SetPlayerPosY(double posY) { y = posY; }
	double GetPlayerPosY() { return y; }

	void SetPlayerDirection(PlayerScope::Direction playerDir) { dir = playerDir; }
	PlayerScope::Direction GetPlayerDirection() { return dir; }
};