#pragma once

/*
///////////////////////////////////////////
CirclePosition�\����

�T�v�@�F�~�`�I�u�W�F�N�g�̊e���W���L�^����Ă���
�g�����F�����蔻������s����ۂ̈����Ƃ��ė^����
///////////////////////////////////////////
*/
struct Circle
{
	int x;
	int y;
	int raddius;
};


/*
///////////////////////////////////////////
CircleShape�N���X

�T�v�@�F�~�̌`����w�肷�邽�߂̃N���X
�g�����F�I�u�W�F�N�g�ɂ��ꂼ��p�������Ďg���B
�@�@�@�@�R���X�g���N�^�ł��A���A���a�����ꂼ��w�肷��K�v����
///////////////////////////////////////////
*/
class CircleShape
{
public:

	Circle circlePosition;

	void SetValue(double *x, double *y, double *raddius)
	{
		this->circlePosition.x = *x;
		this->circlePosition.y = *y;
		this->circlePosition.raddius = *raddius;
	}

	float GetX() const { return circlePosition.x; }
	float GetY() const { return circlePosition.y; }
	float GetRaddius() const { return circlePosition.raddius; }
};