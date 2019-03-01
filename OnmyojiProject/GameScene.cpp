#include "GameScene.h"
#include "SettingProvider.h"
#include "DxLib.h"

/////////////////////////////////////////////////////
//����			:�X�e�[�W��
//�߂�l		:�Ȃ�
//����			:�X�e�[�W�f�[�^��stageDraw�ɑ���
/////////////////////////////////////////////////////
void GameScene::SetStageNum(int num)
{
	// �X�e�[�W�̑������傫�Ȑ������^�����Ȃ��悤�ɐݒ�
	if (MaxStageNum > num) stageNum = num;

	SettingProvider::Instance()->SetStageNumber(num);

	player->SetStageNumber(num);

	// StageDraw�ɃX�e�[�W�f�[�^��n��
	stageDraw->SetStageData(StageInpoter::Instance()->GetStageData()[num]);

	// �v���C���[�̏����ʒu���擾
	position pos = StageInpoter::Instance()->GetPlayerPosData()[num];
	player->SetStartPos(pos.x, pos.y);


	vector<position> rockPos = StageInpoter::Instance()->GetRockPosData()[num];

	for (int i = 0; i < rockPos.size(); i++)
	{
		rock.emplace_back(make_unique<Rock>());
		rock[i]->SetStartPos(rockPos[i].x, rockPos[i].y);
	}

	// �e�X�g�`��p�B
	testVec = StageInpoter::Instance()->GetCollisionData()[num];
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�`��
/////////////////////////////////////////////////////
void GameScene::Draw()
{
	//for (int i = 0; i < testVec.size(); i++)
	//{
		//int x = testVec[i].x;
		//int y = testVec[i].y;
		////DrawCircle(32 + x * 64,32 + y * 64, 5, GetColor(255, 0, 0), TRUE);

		//int top = y * 64;
		//int left = x * 64;
		//int bottom = top + 64;
		//int right = left + 64;

		//DrawBox(left, top, right, bottom, GetColor(255, 0, 0), TRUE);
	//}
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�V
/////////////////////////////////////////////////////
void GameScene::Update()
{
	stageDraw->Update();

	for (int i = 0; i < rock.size(); i++) rock[i]->Update();
	

	//Draw();
	player->Updata();

}