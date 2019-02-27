#include "StageDraw.h"
#include "DxLib.h"
#include "ImageLoader.h"

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�e�[�W��`��
/////////////////////////////////////////////////////
void StageDraw::StillDraw()
{
	DrawGraph(0, 0, ImageLoader::Instance()->GetBackGroundGH(), FALSE);

	for (int i = 0; i < stageHeight; i++)
	{
		for (int j = 0; j < stageWidth; j++)
		{
			DrawRotaGraph(32 + 64 * j, 32 + 64 * i, 0.5, 0.0, ImageLoader::Instance()->GetGameStageGH()[stageData[i][j]], TRUE);
		}
	}
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�`��
/////////////////////////////////////////////////////
void StageDraw::Draw()
{
	StillDraw();
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�V
/////////////////////////////////////////////////////
void StageDraw::Update()
{
	Draw();
}