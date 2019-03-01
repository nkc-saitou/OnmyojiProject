#pragma once

class Rock
{
	const int graphSize = 64;

	double x = 0, y = 0;


	void Move();

	void Draw();

	void Collision();

public:
	// �X�^�[�g���̃|�W�V�������Z�b�g
	void SetStartPos(double posX, double posY);

	void Update();
};