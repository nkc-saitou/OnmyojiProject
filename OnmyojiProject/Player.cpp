#include "Player.h"

#include "DxLib.h"

#include "Collision.h"
#include "StageInpoter.h"
#include "ImageLoader.h"
#include "SettingProvider.h"
#include "CollisionRectProvider.h"
#include "PlayerProvider.h"

#include <cmath>

namespace PlayerScope
{
	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:�v���C���[�̈ړ�
	/////////////////////////////////////////////////////
	void Player::Move()
	{
		// 1920x1080
		const int screenSizeX = SettingProvider::Instance()->screenSizeX;
		const int screenSizeY = SettingProvider::Instance()->screenSizeY;

		// ��Βl�ɕϊ�
		int moveX = abs(tempMoveX);
		int moveY = abs(tempMoveY);

		// ��Βl�łǂ̕����̓��͂�����Ă���̂����擾
		// �܂������ړ����Ă����� 1.0f �ȂȂ߈ړ����Ă����� 0.71f
		if ((moveX >= 900 || moveY >= 900) && (moveX == 0 || moveY == 0)) move = straightMove;
		else if (moveX != 0 && moveY != 0) move = tiltMove;
		else move = straightMove;

		// �ړ�����
		if (tempMoveX < 0) x -= (int)(speed * move);
		if (tempMoveX > 0) x += (int)(speed * move);
		if (tempMoveY < 0) y -= (int)(speed * move);
		if (tempMoveY > 0) y += (int)(speed * move);

		// �ړ����~�߂����́Aidol��Ԃ̉摜�ɕύX����
		if (tempMoveX == 0 && tempMoveY == 0) isMove = false;
		else isMove = true;
	}

	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:�ړ����̃C���[�W�؂�ւ�
	/////////////////////////////////////////////////////
	void Player::MoveGraphSet()
	{
		// ���Ɉړ����Ă���
		if (tempMoveX < 0)
		{
			directionState = Direction::leftDir;

			// xCount���O�ȏ�Ȃ�O�ɂ��Ă���P����
			if (moveCountX > 0) moveCountX = 0;

			if (moveCountX < 40) --moveCountX;
			else moveCountX = 0;
		}
		// �E�Ɉړ����Ă���
		if (tempMoveX > 0)
		{
			directionState = Direction::rightDir;

			// xCount���O�ȉ��Ȃ�O�ɂ��Ă���P����
			if (moveCountX < 0) moveCountX = 0;

			if (moveCountX > -40) ++moveCountX;
			else moveCountX = 0;
		}
		// ��Ɉړ����Ă���
		if (tempMoveY < 0)
		{
			directionState = Direction::upDir;

			// yCount���O�ȏ�Ȃ�O�ɂ��Ă���P����
			if (moveCountY > 0) moveCountY = 0;

			if (moveCountY < 40) --moveCountY;
			else moveCountY = 0;
		}
		// ���Ɉړ����Ă���
		if (tempMoveY > 0)
		{
			directionState = Direction::downDir;

			// yCount���O�ȉ��Ȃ�O�ɂ��Ă���P����
			if (moveCountY < 0) moveCountY = 0;

			if (moveCountY > -40) ++moveCountY;
			else moveCountY = 0;
		}

		// �J�E���g������Y���������߂�
		tempMoveIndexX = abs(moveCountX) % 40 / 10;
		tempMoveIndexY = abs(moveCountY) % 40 / 10;


		// �΂߂Ɉړ����Ă��邩�ǂ����𒲂ׁA�ړ�������ݒ肷��
		if (move == tiltMove)
		{
			if (tempMoveX < 0 && tempMoveY < 0)
			{
				directionState = Direction::upLeftDir;
			}
			else if (tempMoveX < 0 && tempMoveY > 0)
			{
				directionState = Direction::downLeftDir;
			}
			else if (tempMoveX > 0 && tempMoveY < 0)
			{
				directionState = Direction::upRightDir;
			}
			else if (tempMoveX > 0 && tempMoveY > 0)
			{
				directionState = Direction::downRightDir;
			}

			moveIndex = tempMoveIndexX;
		}


		switch (directionState)
		{

			//========== ���ʕ��� ==========

		case Direction::upDir:
			// �����(���p)�Ȃ̂ŁA�Q�s�ڂ̐擪�Y�����z��𑫂�
			tempMoveIndexY += moveDivX;
			moveIndex = tempMoveIndexY;

			break;

		case Direction::downDir:
			// ������(���ʎp)�Ȃ̂ŁA�P�s�ڂ̐擪�Y�����z���result�ɓn��
			moveIndex = tempMoveIndexY;

			break;

		case Direction::leftDir:
			// �������Ȃ̂ŁA�R�s�ڂ̐擪�Y�����z��𑫂�
			tempMoveIndexX += moveDivX * (int)Direction::leftDir;
			moveIndex = tempMoveIndexX;

			break;

		case Direction::rightDir:
			// �E�����Ȃ̂ŁA�S�s�ڂ̐擪�Y�����ԍ��𑫂�
			tempMoveIndexX += moveDivX * (int)Direction::rightDir;
			moveIndex = tempMoveIndexX;

			break;

			//========== �΂ߕ��� ==========

		case Direction::upLeftDir:
			tempMoveIndexX += moveDivX * (int)Direction::leftDir;
			moveIndex = tempMoveIndexX;

			break;

		case Direction::upRightDir:
			tempMoveIndexX += moveDivX * (int)Direction::rightDir;
			moveIndex = tempMoveIndexX;

			break;

		case Direction::downLeftDir:
			tempMoveIndexX += moveDivX * (int)Direction::leftDir;
			moveIndex = tempMoveIndexX;

			break;

		case Direction::downRightDir:
			tempMoveIndexX += moveDivX * (int)Direction::rightDir;
			moveIndex = tempMoveIndexX;

			break;
		}

		// �ړ����Ă��Ȃ��ꍇ�͒l��������
		if (tempMoveY == 0) moveCountY = 0;
		if (tempMoveX == 0) moveCountX = 0;
	}

	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:�ҋ@���̃C���[�W�؂�ւ�
	/////////////////////////////////////////////////////
	void Player::IdolGraphSet()
	{
		if (stopCount < 20) ++stopCount;
		else stopCount = 0;

		tempStopIndex = stopCount % 20 / 10;

		switch (directionState)
		{
		case Direction::upDir:			stopIndex = tempStopIndex + stopDivX;								break;
		case Direction::downDir:		stopIndex = tempStopIndex;											break;
		case Direction::leftDir:		stopIndex = tempStopIndex + stopDivX * (int)Direction::leftDir;		break;
		case Direction::rightDir:		stopIndex = tempStopIndex + stopDivX * (int)Direction::rightDir;	break;
		case Direction::upLeftDir:		stopIndex = tempStopIndex + stopDivX * (int)Direction::leftDir;		break;
		case Direction::upRightDir:		stopIndex = tempStopIndex + stopDivX * (int)Direction::rightDir;	break;
		case Direction::downLeftDir:	stopIndex = tempStopIndex + stopDivX * (int)Direction::leftDir;		break;
		case Direction::downRightDir:	stopIndex = tempStopIndex + stopDivX * (int)Direction::rightDir;	break;
		}
	}

	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:�����蔻��p�̏���
	/////////////////////////////////////////////////////
	void Player::Collision()
	{
		if (playerCollision->OnCollision(x, y))
		{
			// �H�����܂Ȃ��悤�Ɉʒu��߂�
			x = memoryX;
			y = memoryY;

			return;
		}

		// �ՓˑO�̈ʒu���L�^���Ă���
		memoryX = x;
		memoryY = y;
	}

	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:�`��p�̃f�[�^��o�^
	/////////////////////////////////////////////////////
	void Player::SetLayerData()
	{
		if (isMove) rendererData.gh = ImageLoader::Instance()->GetPlayerWalkGH()[moveIndex];
		else rendererData.gh = ImageLoader::Instance()->GetPlayerIdolGH()[stopIndex];

		rendererData.x = x;
		rendererData.y = y;
		rendererData.orderInLayer = 0;
		rendererData.layerType = LayerType::object;
		rendererData.TransparencySortFlg = TRUE;
		rendererData.transFlg = TRUE;
	}


	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:�`��
	/////////////////////////////////////////////////////
	void Player::Draw()
	{
		MoveGraphSet();
		IdolGraphSet();

		SetLayerData();

		//// �v���C���[�\��
		//if (isMove) DrawGraph(x, y, ImageLoader::Instance()->GetPlayerWalkGH()[moveIndex], TRUE);
		//else DrawGraph(x, y, ImageLoader::Instance()->GetPlayerIdolGH()[stopIndex], TRUE);
	}

	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:�����蔻��̍��W��o�^
	/////////////////////////////////////////////////////
	void Player::SetPosition()
	{
		// �����蔻���t����͈͂�ݒ肵�Ă���
		double top = y + collisionOffset;
		double bottom = y + graphSize;
		double left = x + collisionOffset;
		double right = x + graphSize - collisionOffset;

		// �l��ۑ�
		SetValue(&top, &bottom, &left, &right);
	}

	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:�X�^�[�g���̃|�W�V�������Z�b�g
	/////////////////////////////////////////////////////
	void Player::SetStartPos(double posX, double posY)
	{
		x = posX * graphSize;
		y = posY * graphSize;
	}

	/////////////////////////////////////////////////////
	//����			:�Ȃ�
	//�߂�l		:�Ȃ�
	//����			:�X�V
	/////////////////////////////////////////////////////
	void Player::Updata()
	{
		// �A�i���O�X�e�B�b�N�̉�]�p�x(-1000 ~ 1000)�̎擾
		tempMoveX = plyaerInput->GetMoveAngleX();
		tempMoveY = plyaerInput->GetMoveAngleY();

		// �v���C���[���͂��X�V
		plyaerInput->Update();

		// �v���C���[�̌������L�����Ă���
		PlayerProvider::Instance()->SetPlayerDirection(directionState);

		// �v���C���[�̍��W���L�����Ă���
		PlayerProvider::Instance()->SetPlayerPosX(x);
		PlayerProvider::Instance()->SetPlayerPosY(y);

		// ���CollisionRectProvider��Player��Rect���Ď�����
		Rect rect = GetRect();
		CollisionRectProvider::Instance()->SetPlayerRect(rect);

		if (SettingProvider::Instance()->GetIsClear() == false)
		{
			// �����蔻��
			Collision();

			Move();

			SetPosition();
		}

		Draw();

	}

}