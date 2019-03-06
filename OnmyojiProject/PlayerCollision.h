#pragma once

#include "StageInpoter.h"
#include "ObjectCollision.h"
#include "SettingProvider.h"

namespace PlayerScope
{
	/*
	///////////////////////////////////////////
	PlayerCollision�N���X

	�T�v�@�F�v���C���[�̓����蔻��̊Ǘ�
	///////////////////////////////////////////
	*/
	class PlayerCollision
	{
		std::unique_ptr<ObjectCollision> objectCollision = std::make_unique<ObjectCollision>();

		const int graphSize = 64;
		const int screenSizeX = SettingProvider::Instance()->screenSizeX;
		const int screenSizeY = SettingProvider::Instance()->screenSizeY;

	public:

		// �����ɂ����������ǂ���
		bool OnCollision(int x, int y);
	};
}