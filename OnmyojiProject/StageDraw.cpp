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
			DrawExtendGraph(64 * j, 64 * i, (64 * j) + 64, (64 * i) + 64, ImageLoader::Instance()->GetGameStageGH()[stageData[i][j]], TRUE);
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