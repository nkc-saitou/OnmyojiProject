#include "GameScene.h"
#include "SettingProvider.h"
#include "CollisionRectProvider.h"
#include "DxLib.h"

/////////////////////////////////////////////////////
//����			:�X�e�[�W�ԍ�
//�߂�l		:�Ȃ�
//����			:�X�e�[�W�f�[�^��stageDraw�ɑ���
/////////////////////////////////////////////////////
void GameScene::SetStage(int num)
{
	// �X�e�[�W�̑������傫�Ȑ������^�����Ȃ��悤�ɐݒ�
	if (MaxStageNum > num) stageNum = num;

	// �X�e�[�W�ԍ����L�^�����Ă���
	SettingProvider::Instance()->SetStageNumber(stageNum);

	// StageDraw�ɃX�e�[�W�f�[�^��n��
	stageDraw->SetStageData(StageInpoter::Instance()->GetStageData()[stageNum]);

	// �X�e�[�W�̓����蔻���ݒ肷��
	stageCollision->SetCollsionPosition();

	// �S�[���̈ʒu���Z�b�g
	createGoalPoint->Init();

	// �v���C���[�̏����ʒu���擾
	position pos = StageInpoter::Instance()->GetPlayerPosData()[stageNum];
	player->SetStartPos(pos.x, pos.y);

	// rockController�̏����ʒu���Z�b�g����
	rockController->RockStartPosSet(stageNum);

	// �e�X�g�`��p
	testVec = CollisionRectProvider::Instance()->GetStageRect();
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�`��
/////////////////////////////////////////////////////
void GameScene::Draw()
{
	for (int i = 0; i < testVec.size(); i++)
	{
		DrawBox(testVec[i].left, testVec[i].top, testVec[i].right, testVec[i].bottom, GetColor(255, 0, 0), TRUE);
	}

	Rect top = CollisionRectProvider::Instance()->GetTopEdgeStageRect();
	Rect bottom = CollisionRectProvider::Instance()->GetBottomEdgeStageRect();
	Rect left = CollisionRectProvider::Instance()->GetLeftEdgeStageRect();
	Rect right = CollisionRectProvider::Instance()->GetRightEdgeStageRect();

	DrawBox(top.left, top.top, top.right, top.bottom, GetColor(255, 0, 0), TRUE);
	DrawBox(bottom.left, bottom.top, bottom.right, bottom.bottom, GetColor(255, 0, 0), TRUE);
	DrawBox(left.left, left.top, left.right, left.bottom, GetColor(255, 0, 0), TRUE);
	DrawBox(right.left, right.top, right.right, right.bottom, GetColor(255, 0, 0), TRUE);
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

	rockController->Update();

	//Draw();

}