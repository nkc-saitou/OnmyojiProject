#pragma once

#include "StageInpoter.h"
#include "ObjectCollision.h"
#include "SettingProvider.h"
#include "E_CollisionObj.h"

#include <vector>
#include <memory>

namespace RockScope {

	/*
	///////////////////////////////////////////
	SceneStage�񋓑�

	�T�v�@�F�V�[���̏�Ԃ𔻕ʂ���
	///////////////////////////////////////////
	*/
	class RockCollision
	{
		const int graphSize = 64;
		const int screenSizeX = SettingProvider::Instance()->screenSizeX;
		const int screenSizeY = SettingProvider::Instance()->screenSizeY;

		std::unique_ptr<ObjectCollision> objectCollision = std::make_unique<ObjectCollision>();

	public:

		bool OnCollision(Rect myRockRect,int x,int y,Rect& collisionRect, CollisionObjType& type);
	};
}