#pragma once

#include "RectShape.h"

#include "PlayerCollision.h"
#include "SettingProvider.h"
#include "E_PlayerDirection.h"
#include "PlayerInput.h"
#include "ImageRenderer.h"

#include <memory>

namespace PlayerScope
{
	/*
	///////////////////////////////////////////
	Player�N���X

	�T�v�@�F�v���C���[�̕\���A�����𐧌�
	///////////////////////////////////////////
	*/
	class  Player : public RectShape
	{
		//===============================
		// �ϐ�
		//===============================

	private:

		std::unique_ptr<PlayerCollision> playerCollision = std::make_unique<PlayerCollision>();
		std::unique_ptr<PlayerInput> plyaerInput = std::make_unique<PlayerInput>();
		std::unique_ptr<ImageRenderer> imageRenderer = std::make_unique<ImageRenderer>();

		// �C���[�W�̃T�C�Y�B�c���Ƃ���64px
		const int graphSize = 64;

		const int collisionOffset = 20;

		// �ړ����Ă���Ƃ��̉��̕�����
		const int moveDivX = 4;

		// �~�܂��Ă���Ƃ��̉��̕�����
		const int stopDivX = 2;

		// �A�i���O�X�e�B�b�N�̉�]�x���擾
		int tempMoveX = 0, tempMoveY = 0;

		// �������Əc�����̃J�E���g��
		int moveCountX = 0, moveCountY = 0;

		// �ҋ@
		int stopCount = 0, tempStopIndex = 0, stopIndex = 0;

		//�Y�����p�ϐ�
		int tempMoveIndexX = 0, tempMoveIndexY = 0, moveIndex = 0;

		int stageNum = 0;

		// �ړ����W�L��
		double memoryX = x;
		double memoryY = y;

		// ���W
		double x, y;

		//�ړ����Ă��邩�ǂ��� �ړ����Ă�����true
		bool isMove = false;

		// �ړ��X�s�[�h
		double speed = 4.0;

		// �ړ��W��
		double move = 1.0;

		// �܂������i��ł���Ƃ��̈ړ��W���̒l
		double straightMove = 1.0;

		// �΂߂ɐi��ł���Ƃ��̈ړ��W���̒l
		double tiltMove = 0.8;

		// ���݂̕���
		Direction directionState = Direction::upDir;

		// �`��p�f�[�^
		RendererData rendererData;

		//===============================
		// �֐�
		//===============================

		// �ړ�����
		void Move();
		// �ړ������ۂ̃C���[�W�̕ύX����
		void MoveGraphSet();
		// �ҋ@��Ԃ̃C���[�W�ύX����
		void IdolGraphSet();
		// �����蔻��
		void Collision();
		// �\������
		void Draw();
		// �����蔻��̍��W��o�^
		void SetPosition();
		// �`��f�[�^��o�^
		void SetLayerData();

	public:

		// �X�^�[�g���̃|�W�V�������Z�b�g
		void SetStartPos(double posX, double posY);

		void Updata();

		// �v���C���[�̌������擾�ł���
		Direction GetPlayerDirection() { return directionState; }
	};
}