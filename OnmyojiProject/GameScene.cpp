#include "GameScene.h"

/////////////////////////////////////////////////////
//����			:�X�e�[�W��
//�߂�l		:�Ȃ�
//����			:�X�e�[�W�f�[�^��stageDraw�ɑ���
/////////////////////////////////////////////////////
void GameScene::SetStageNum(int num)
{
	// �X�e�[�W�̑������傫�Ȑ������^�����Ȃ��悤�ɐݒ�
	if (MaxStageNum > num) stageNum = num;

	// StageDraw�ɃX�e�[�W�f�[�^��n��
	stageDraw->SetStageData(StageInpoter::Instance()->GetStageData()[num]);
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�`��
/////////////////////////////////////////////////////
void GameScene::Draw()
{
	
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�V
/////////////////////////////////////////////////////
void GameScene::Update()
{
	stageDraw->Update();
	player->Updata();
}