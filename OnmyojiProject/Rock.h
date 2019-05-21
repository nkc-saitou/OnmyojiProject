#pragma once

#include "RectShape.h"
#include "RockCollision.h"
#include "E_PlayerDirection.h"
#include "ImageRenderer.h"

namespace RockScope {

	/*
	///////////////////////////////////////////
	Rock�N���X

	�T�v�@�F�ΒP�̂𐧌䂷��N���X
	///////////////////////////////////////////
	*/
	class Rock : public RectShape
	{

		std::unique_ptr<RockCollision> rockCollision = std::make_unique<RockCollision>();
		std::unique_ptr<ImageRenderer> imageRenderer = std::make_unique<ImageRenderer>();

		const int graphSize = 64;

		const int offset = 20;

		const double speed = 1.0;

		const double backMove = 2.0;


		double x = 0, y = 0;

		double memoryX = 0, memoryY = 0;

		bool isMove = false;

		bool isGoal = false;


		PlayerScope::Direction playerDir;

		// �`��p�f�[�^
		RendererData rendererData;

		void Draw();

		void Collision();

		void RectSet();

		// �`��f�[�^��o�^
		void SetLayerData();

	public:
		// �X�^�[�g���̃|�W�V�������Z�b�g
		void SetStartPos(double posX, double posY);

		void Move(PlayerScope::Direction dir);

		void Update();

		void IsMove(bool tempIsMove) { isMove = tempIsMove; }

		bool IsGoal() { return isGoal; }
	};
}