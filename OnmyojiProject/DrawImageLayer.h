#pragma once

#include "Singleton.h"
#include "E_LayerType.h"

/*
///////////////////////////////////////////
DrawImageLayerクラス

概要　：レイヤー管理クラス
///////////////////////////////////////////
*/
class DrawImageLayer : public Singleton <DrawImageLayer>
{
	void DrawLayer(int x,int y, int gh, int transFlg,LayerType type,int oderLayer = 0);
};