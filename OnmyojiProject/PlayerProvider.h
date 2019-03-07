#pragma once
#include "Singleton.h"
#include "E_PlayerDirection.h"

/*
///////////////////////////////////////////
PlayerProvider�N���X

�T�v�@�F�v���C���[�̍��W��������擾�ł���
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