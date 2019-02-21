#pragma once

#include "RectShape.h"
#include <memory>

/*
///////////////////////////////////////////
Direction�񋓑�

�T�v�@�F�ړ������̏�Ԃ��Ǘ�����
///////////////////////////////////////////
*/
enum Direction
{
	up = 0,
	down,
	left,
	right
};

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
	// �C���[�W�̃T�C�Y�B�c���Ƃ���64px
	const int graphSize = 64;

	// �C���[�W�S�̂̕�����
	const int allDivision = 12;

	// ���̕�����
	const int divisionX = 3;

	// �c�̕�����
	const int divisionY = 4;


	// �O���t�B�b�N�n���h��
	int walkGh[12];
	int idolGh[8];

	// �A�i���O�X�e�B�b�N�̉�]�x���擾
	int tempMoveX = 0, tempMoveY = 0;

	// �������Əc�����̃J�E���g��
	int xCount = 0, yCount = 0;

	//�Y�����p�ϐ�
	int ix = 0, iy = 0, result = 0;


	// ���W
	double x = 360, y = 200;


	// �ړ��X�s�[�h
	float speed = 3.0f;

	// �ړ��W��
	float move = 1.0f;


	// ���݂̕���
	Direction directionState = down;

	//===============================
	// �֐�
	//===============================

	// �ړ�����
	void Move();
	// �ړ������ۂ̃C���[�W�̕ύX����
	void MoveGraphSet();
	// �����蔻��
	void Collision();
	// �\������
	void Draw(); 
	// �����蔻��̍��W��o�^
	void SetPosition();

public:
	Player();
	void Update();
};