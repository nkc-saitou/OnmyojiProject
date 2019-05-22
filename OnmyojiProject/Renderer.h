#pragma once

#include "Singleton.h"
#include "E_LayerType.h"

#include "Player.h"
#include "RockController.h"

/*
///////////////////////////////////////////
DrawImageLayerクラス

概要　：レイヤー管理クラス
///////////////////////////////////////////
*/
class Renderer : public Singleton <Renderer>
{
	void DrawLayer(int x,int y, int gh, int transFlg,LayerType type,int oderLayer = 0);
};