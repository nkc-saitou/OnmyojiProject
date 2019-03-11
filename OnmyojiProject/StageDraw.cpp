#include "StageDraw.h"
#include "DxLib.h"
#include "ImageLoader.h"

StageDraw::StageDraw(SceneState state)
{
	sceneState = state;
}


/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�e�[�W��`��
/////////////////////////////////////////////////////
void StageDraw::StillDraw()
{
	if (sceneState == SceneState::gameScene)
		DrawGraph(0, 0, ImageLoader::Instance()->GetBackGroundGH(), FALSE);
	else if(sceneState == SceneState::resultScene)
		DrawGraph(0, 0, ImageLoader::Instance()->GetBackClearGroundGh(), FALSE);

	for (int i = 0; i < stageHeight; i++)
	{
		for (int j = 0; j < stageWidth; j++)
		{
			if(sceneState == SceneState::gameScene)
				DrawExtendGraph(64 * j, 64 * i, (64 * j) + 64, (64 * i) + 64, ImageLoader::Instance()->GetGameStageGH()[stageData[i][j]], TRUE);
			else if (sceneState == SceneState::resultScene)
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