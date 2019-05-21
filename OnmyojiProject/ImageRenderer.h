#pragma once

#include "E_LayerType.h"

struct  RendererData
{
	int x;
	int y;
	int gh;
	int transFlg;
	LayerType layerType;
	int TransparencySortFlg;
	int orderInLayer = 0;
};

/*
///////////////////////////////////////////
DrawImageLayerクラス

概要　：レイヤー管理クラス
///////////////////////////////////////////
*/
class ImageRenderer
{

	RendererData _rendererData;

public:
	// Imageの情報を取得させる
	void SetImageRenderer(RendererData &rendererData) { _rendererData = rendererData; }

	// Imageの情報を公開
	RendererData GetImageRenderer() { return _rendererData; }

};