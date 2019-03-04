#pragma once

#include "RectShape.h"

class Rock : public RectShape
{
	const int graphSize = 64;

	double x = 0, y = 0;

	bool isOnCollison = false;


	void Move();

	void Draw();

	void Collision();

	void RectSet();

public:
	// �X�^�[�g���̃|�W�V�������Z�b�g
	void SetStartPos(double posX, double posY);

	void Update();

	bool SetIsOnCollision(bool isCollison) { isOnCollison = isCollison; }
};