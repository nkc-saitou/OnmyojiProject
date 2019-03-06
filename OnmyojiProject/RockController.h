#pragma once

#include <vector>
#include <memory>

#include "Rock.h"
#include "PlayerInput.h"

namespace RockScope
{
	/*
	///////////////////////////////////////////
	RockControler�N���X

	�T�v�@�F�΃I�u�W�F�N�g�S�̂̐���
	///////////////////////////////////////////
	*/

	class RockController
	{
		std::vector<std::unique_ptr<Rock>> rock;

		std::unique_ptr<PlayerScope::PlayerInput> playerInput = std::make_unique<PlayerScope::PlayerInput>();

		PlayerScope::Direction dir;

	public:

		// ��̏����ʒu���Z�b�g
		void RockStartPosSet(int stageNum);

		// ��̓����蔻����Z�b�g
		void RockCollisonSet();

		// �X�V
		void Update();

	};
}