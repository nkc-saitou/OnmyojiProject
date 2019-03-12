#include "GameScene.h"
#include "SettingProvider.h"
#include "CollisionRectProvider.h"
#include "E_SceneState.h"
#include "Input.h"

#include "FadeManager.h"
#include "ImageLoader.h"
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


	stageDraw = std::make_unique<StageDraw>(SceneState::gameScene);
	player = std::make_unique<PlayerScope::Player>();
	stageCollision = std::make_unique<StageCollision>();
	rockController = std::make_unique<RockScope::RockController>();
	createGoalPoint = std::make_unique<CreateGoalPoint>();

	SettingProvider::Instance()->SetClearFlg(false);

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


	isTest = false;
}

void GameScene::GameClear()
{
	if (CollisionRectProvider::Instance()->GetGoalRect().size() == 0 || isTest == true)
	{
		if (FadeManager::Instance()->IsWhiteFadeIn())
		{
			SettingProvider::Instance()->SetClearFlg(true);
			SettingProvider::Instance()->SetSceneState(SceneState::resultScene);
		}

	}
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
	if (Input::Instance()->ButtonDown(XINPUT_BUTTON_Y,Pad_1) || Input::Instance()->ButtonDown(KEY_INPUT_X))
		SettingProvider::Instance()->SetSceneState(SceneState::titleScene);

	if (Input::Instance()->ButtonDown(KEY_INPUT_T)) isTest = true;

	stageDraw->Update();

	player->Updata();

	rockController->Update();


	// �W����p�@�I����������
	DrawGraph(0, 0, ImageLoader::Instance()->GetGameEffectGh(), TRUE);

	DrawGraph(oneEffect, 0, ImageLoader::Instance()->GetGameEffectMoveGh(), TRUE);
	DrawGraph(twoEffect, 0, ImageLoader::Instance()->GetGameEffectMoveGh(), TRUE);

	oneEffect = (oneEffect > -1920) ? (oneEffect - 1) : 1920;
	twoEffect = (twoEffect > -1920) ? (twoEffect - 1) : 1920;




	GameClear();


	//Draw();
}