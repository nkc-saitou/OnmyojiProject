#include "Player.h"
#include "DxLib.h"
#include "Input.h"

#include <cmath>

Player::Player() : RectShape()
{
	// �摜�ǂݍ���
	LoadDivGraph("test.png", allDivision, divisionX, divisionY, graphSize, graphSize, walkGh);
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�v���C���[�̈ړ�
/////////////////////////////////////////////////////
void Player::Move()
{
	// ��Βl�ɕϊ�
	int moveX = abs(tempMoveX);
	int moveY = abs(tempMoveY);

	// ��Βl�łǂ̕����̓��͂�����Ă���̂����擾
	// �܂������ړ����Ă����� 1.0f �ȂȂ߈ړ����Ă����� 0.71f
	if ((moveX == 1000 || moveY == 1000) && (moveX == 0 || moveY == 0)) move = 1.0f;
	else if(moveX != 0) move = 0.71f;

	// �ړ�����
	if (tempMoveX < 0) x -= (int)(speed * move);
	if (tempMoveX > 0) x += (int)(speed * move);
	if (tempMoveY < 0) y -= (int)(speed * move);
	if (tempMoveY > 0) y += (int)(speed * move);

	// �������A��ʊO�ɏo�Ȃ��悤��
	if (x + 64 > 1600) x = 1600 - 64;
	if (x < 64) x = 64;
	// �������A��ʊO�ɏo�Ȃ��悤��
	if (y + 64 > 900) y = 900 -64;
	if (y < 64) y = 64;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�v���C���[�̃C���[�W�؂�ւ�
/////////////////////////////////////////////////////
void Player::MoveGraphSet()
{
	// ���Ɉړ����Ă���
	if (tempMoveX < 0)
	{
		directionState = left;

		// xCount���O�ȏ�Ȃ�O�ɂ��Ă���P����
		if (xCount > 0) xCount = 0;

		if(xCount < 30) --xCount;
		else xCount = 0;
	}
	// �E�Ɉړ����Ă���
	if (tempMoveX > 0)
	{
		directionState = right;

		// xCount���O�ȉ��Ȃ�O�ɂ��Ă���P����
		if (xCount < 0) xCount = 0;

		if(xCount > -30) ++xCount;
		else xCount = 0;
	}
	// ��Ɉړ����Ă���
	if (tempMoveY < 0)
	{
		directionState = up;

		// yCount���O�ȏ�Ȃ�O�ɂ��Ă���P����
		if (yCount > 0) yCount = 0;

		if(yCount < 30) --yCount;
		else yCount = 0;
	}
	// ���Ɉړ����Ă���
	if (tempMoveY > 0)
	{
		directionState = down;

		// yCount���O�ȉ��Ȃ�O�ɂ��Ă���P����
		if (yCount < 0) yCount = 0;

		if(yCount > -30) ++yCount;
		else yCount = 0;
	}

	// �J�E���g������Y���������߂�
	ix = abs(xCount) % 30 / 10;
	iy = abs(yCount) % 30 / 10;

	// �E�������Ă���
	if (xCount > 0)
	{
		// �E�����Ȃ̂ŁA�R�s�ڂ̐擪�Y�����ԍ��𑫂�
		ix += divisionX * 2;
		result = ix;
	}
	// ���������Ă���
	else if (xCount < 0)
	{
		// �������Ȃ̂ŁA�Q�s�ڂ̐擪�Y�����z��𑫂�
		ix += divisionX;
		result = ix;
	}

	// ���������Ă���
	if (yCount < 0)
	{
		// �������Ȃ̂ŁA�S�s�ڂ̐擪�Y�����z��𑫂�
		iy += divisionX * 3;
		result = iy;
	}
	// ��������Ă���
	else if (yCount > 0)
	{
		result = iy;
	}

	// �΂߈ړ��̏ꍇ�͉����D��
	if (move == 0.71f) result = ix;

	// �ړ����Ă��Ȃ��ꍇ�͒l��������
	if (tempMoveY == 0) yCount = 0;
	if (tempMoveX == 0) xCount = 0;

	// �ړ����~�߂����́A�~�܂�O�܂Ō����Ă��������̊G�̐擪��\������
	if (tempMoveX == 0 && tempMoveY == 0)
	{
		switch (directionState)
		{
		case down:	result = 0;				break;
		case left:	result = divisionX;		break;
		case right:	result = divisionX * 2; break;
		case up:	result = divisionX * 3; break;
		}
	}
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�����蔻��p�̏���
/////////////////////////////////////////////////////
void Player::Collision()
{

}


/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�`��
/////////////////////////////////////////////////////
void Player::Draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "x:%lf y:%lf",x, y);

	MoveGraphSet();

	// �v���C���[�\��
	DrawGraph(x, y, walkGh[result], TRUE);
	DrawCircle(x, y, 10, GetColor(255, 0, 0), TRUE);

}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�����蔻��̍��W��o�^
/////////////////////////////////////////////////////
void Player::SetPosition()
{
	double top	  =  y;
	double bottom =  y + graphSize;
	double left   =  x;
	double right  =  x + graphSize;

	SetValue(&top, &bottom, &left, &right);
}


/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�V
/////////////////////////////////////////////////////
void Player::Update()
{
	// �A�i���O�X�e�B�b�N�̉�]�p�x(-1000 ~ 1000)�̎擾
	tempMoveX = Input::Instance()->AngleInputX(Pad_1);
	tempMoveY = Input::Instance()->AngleInputY(Pad_1);


	DrawFormatString(100, 600, GetColor(255, 255, 255), "top:%lf bottom:%lf left:%lf right:%lf", GetTop(), GetBottom(),GetLeft(),GetRight());

	Move();
	Draw();
	SetPosition();
}