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
DrawImageLayer�N���X

�T�v�@�F���C���[�Ǘ��N���X
///////////////////////////////////////////
*/
class ImageRenderer
{

	RendererData _rendererData;

public:
	// Image�̏����擾������
	void SetImageRenderer(RendererData &rendererData) { _rendererData = rendererData; }

	// Image�̏������J
	RendererData GetImageRenderer() { return _rendererData; }

};