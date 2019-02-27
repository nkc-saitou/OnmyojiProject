#include "Player.h"
#include "DxLib.h"
#include "Input.h"
#include "SettingProvider.h"

#include <cmath>

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�v���C���[�̈ړ�
/////////////////////////////////////////////////////
void Player::Move()
{
	// 1920x1080
	const int screenSizeX = SettingProvider::screenSizeX;
	const int screenSizeY = SettingProvider::screenSizeY;

	// ��Βl�ɕϊ�
	int moveX = abs(tempMoveX);
	int moveY = abs(tempMoveY);

	// ��Βl�łǂ̕����̓��͂�����Ă���̂����擾
	// �܂������ړ����Ă����� 1.0f �ȂȂ߈ړ����Ă����� 0.71f
	if ((moveX >= 900 || moveY >= 900) && (moveX == 0 || moveY == 0)) move = straightMove;
	else if(moveX != 0 && moveY != 0) move = tiltMove;
	else move = straightMove;

	// �ړ�����
	if (tempMoveX < 0) x -= (int)(speed * move);
	if (tempMoveX > 0) x += (int)(speed * move);
	if (tempMoveY < 0) y -= (int)(speed * move);
	if (tempMoveY > 0) y += (int)(speed * move);

	// �������A��ʊO�ɏo�Ȃ��悤��
	if (x + graphSize > screenSizeX) x = screenSizeX - graphSize;
	if (x < graphSize) x = graphSize;
	// �������A��ʊO�ɏo�Ȃ��悤��
	if (y + graphSize > screenSizeY) y = screenSizeY - graphSize;
	if (y < graphSize) y = graphSize;

	// �ړ����~�߂����́Aidol��Ԃ̉摜�ɕύX����
	if (tempMoveX == 0 && tempMoveY == 0) isMove = false;
	else isMove = true;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�ړ����̃C���[�W�؂�ւ�
/////////////////////////////////////////////////////
void Player::MoveGraphSet()
{
	// ���Ɉړ����Ă���
	if (tempMoveX < 0)
	{
		directionState = left;

		// xCount���O�ȏ�Ȃ�O�ɂ��Ă���P����
		if (moveCountX > 0) moveCountX = 0;

		if(moveCountX < 40) --moveCountX;
		else moveCountX = 0;
	}
	// �E�Ɉړ����Ă���
	if (tempMoveX > 0)
	{
		directionState = right;

		// xCount���O�ȉ��Ȃ�O�ɂ��Ă���P����
		if (moveCountX < 0) moveCountX = 0;

		if(moveCountX > -40) ++moveCountX;
		else moveCountX = 0;
	}
	// ��Ɉړ����Ă���
	if (tempMoveY < 0)
	{
		directionState = up;

		// yCount���O�ȏ�Ȃ�O�ɂ��Ă���P����
		if (moveCountY > 0) moveCountY = 0;

		if(moveCountY < 40) --moveCountY;
		else moveCountY = 0;
	}
	// ���Ɉړ����Ă���
	if (tempMoveY > 0)
	{
		directionState = down;

		// yCount���O�ȉ��Ȃ�O�ɂ��Ă���P����
		if (moveCountY < 0) moveCountY = 0;

		if(moveCountY > -40) ++moveCountY;
		else moveCountY = 0;
	}

	// �J�E���g������Y���������߂�
	tempMoveIndexX = abs(moveCountX) % 40 / 10;
	tempMoveIndexY = abs(moveCountY) % 40 / 10;


	// �΂߈ړ��̏ꍇ�͉����D��
	if (move == tiltMove)
	{
		if (moveCountX > 0) directionState = right;
		else directionState = left;

		moveIndex = tempMoveIndexX;
	}


	switch (directionState)
	{
	case up:
		// �������Ȃ̂ŁA�Q�s�ڂ̐擪�Y�����z��𑫂�
		tempMoveIndexY += moveDivX;
		moveIndex = tempMoveIndexY;
		break;

	case down: 
		// ������Ȃ̂ŁA�P�s�ڂ̐擪�Y�����z���result�ɓn��
		moveIndex = tempMoveIndexY;
		break;

	case left: 
		// �������Ȃ̂ŁA�R�s�ڂ̐擪�Y�����z��𑫂�
		tempMoveIndexX += moveDivX * left;
		moveIndex = tempMoveIndexX;
		break;

	case right: 
		// �E�����Ȃ̂ŁA�S�s�ڂ̐擪�Y�����ԍ��𑫂�
		tempMoveIndexX += moveDivX * right;
		moveIndex = tempMoveIndexX;
		break;
	}

	int t = directionState;

	DrawFormatString(100, 100, GetColor(255, 0, 0), "direction : %d  x:%d y:%d", t, moveCountX, moveCountY);

	// �ړ����Ă��Ȃ��ꍇ�͒l��������
	if (tempMoveY == 0) moveCountY = 0;
	if (tempMoveX == 0) moveCountX = 0;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�ҋ@���̃C���[�W�؂�ւ�
/////////////////////////////////////////////////////
void Player::IdolGraphSet()
{
	if (stopCount < 20) ++stopCount;
	else stopCount = 0;

	tempStopIndex = stopCount % 20 / 10;
	
	switch (directionState)
	{
	case down:	stopIndex = tempStopIndex;						break;
	case up:	stopIndex = tempStopIndex + stopDivX;			break;
	case left:	stopIndex = tempStopIndex + stopDivX * left;	break;
	case right: stopIndex = tempStopIndex + stopDivX * right;	break;
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

	MoveGraphSet();
	IdolGraphSet();

	// �v���C���[�\��
	if(isMove) DrawGraph(x, y, ImageLoader::Instance()->GetPlayerWalkGH()[moveIndex], TRUE);
	else DrawGraph(x, y, ImageLoader::Instance()->GetPlayerIdolGH()[stopIndex], TRUE);
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
void Player::Updata()
{
	// �A�i���O�X�e�B�b�N�̉�]�p�x(-1000 ~ 1000)�̎擾
	tempMoveX = Input::Instance()->AngleInputX(Pad_1);
	tempMoveY = Input::Instance()->AngleInputY(Pad_1);


	//DrawFormatString(100, 600, GetColor(255, 255, 255), "top:%lf bottom:%lf left:%lf right:%lf", GetTop(), GetBottom(),GetLeft(),GetRight());

	Move();
	Draw();
	SetPosition();
}