#pragma once

#include "Singleton.h"
#include "E_LayerType.h"

/*
///////////////////////////////////////////
DrawImageLayer�N���X

�T�v�@�F���C���[�Ǘ��N���X
///////////////////////////////////////////
*/
class DrawImageLayer : public Singleton <DrawImageLayer>
{
	void DrawLayer(int x,int y, int gh, int transFlg,LayerType type,int oderLayer = 0);
};