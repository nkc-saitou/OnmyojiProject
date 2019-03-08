#include "RockController.h"

#include "StageInpoter.h"
#include "Input.h"
#include "SettingProvider.h"
#include "CollisionRectProvider.h"
#include "PlayerProvider.h"

namespace RockScope
{
	using namespace std;
	using namespace PlayerScope;

	/////////////////////////////////////////////////////
	//����			:�X�e�[�W�ԍ�
	//�߂�l		:�Ȃ�
	//����			:��̏����ʒu��ݒ�
	/////////////////////////////////////////////////////
	void RockController::RockStartPosSet(int stageNum)
	{
		std::vector<position> rockPos = StageInpoter::Instance()->GetRockPosData()[stageNum];

		for (int i = 0; i < rockPos.size(); i++)
		{
			rock.emplace_back(make_unique<Rock>());
			rock[i]->SetStartPos(rockPos[i].x, rockPos[i].y);
		}
	}

	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:��̓����蔻����Z�b�g
	/////////////////////////////////////////////////////
	void RockController::RockCollisonSet()
	{
		vector<Rect> tempRect;

		for (int i = 0; i < rock.size(); i++)
		{
			if(rock[i]->IsGoal() != true) tempRect.push_back(rock[i]->GetRect());
		}

		// �����蔻�����
		CollisionRectProvider::Instance()->SetRockRect(tempRect);
	}

	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:�X�V
	/////////////////////////////////////////////////////
	void RockController::Update()
	{
		// �v���C���[�̓��͂��X�V
		playerInput->Update();

		// �A�N�V�����{�^����������Ă�����
		if (playerInput->GetIsAction())
		{
			// �v���C���[�̌�����ۑ�
			dir = PlayerProvider::Instance()->GetPlayerDirection();

			// ��𓮂���
			for (int i = 0; i < rock.size(); i++) rock[i]->IsMove(true);
		}

		// �₻�ꂼ����X�V
		for (int i = 0; i < rock.size(); i++)
		{
			rock[i]->Update();
			// ����v���C���[�̌����ɓ�����
			rock[i]->Move(dir);
		}


		RockCollisonSet();
	}

}