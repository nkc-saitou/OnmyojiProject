#include "Player.h"
#include "DxLib.h"
#include "Input.h"
#include "SettingProvider.h"
#include "StageInpoter.h"
#include "Collision.h"
#include "RectWatcher.h"

#include <cmath>

void Player::SetStageNumber()
{
	stageNum = SettingProvider::Instance()->GetStageNumber();
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�v���C���[�̈ړ�
/////////////////////////////////////////////////////
void Player::Move()
{
	// 1920x1080
	const int screenSizeX = SettingProvider::Instance()->screenSizeX;
	const int screenSizeY = SettingProvider::Instance()->screenSizeY;

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
	if (x + graphSize * 2 > screenSizeX) x = screenSizeX - graphSize * 2;
	if (x < graphSize) x = graphSize;
	// �������A��ʊO�ɏo�Ȃ��悤��
	if (y + graphSize * 2 > screenSizeY) y = screenSizeY - graphSize * 2;
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
		directionState = leftDir;

		// xCount���O�ȏ�Ȃ�O�ɂ��Ă���P����
		if (moveCountX > 0) moveCountX = 0;

		if(moveCountX < 40) --moveCountX;
		else moveCountX = 0;
	}
	// �E�Ɉړ����Ă���
	if (tempMoveX > 0)
	{
		directionState = rightDir;

		// xCount���O�ȉ��Ȃ�O�ɂ��Ă���P����
		if (moveCountX < 0) moveCountX = 0;

		if(moveCountX > -40) ++moveCountX;
		else moveCountX = 0;
	}
	// ��Ɉړ����Ă���
	if (tempMoveY < 0)
	{
		directionState = upDir;

		// yCount���O�ȏ�Ȃ�O�ɂ��Ă���P����
		if (moveCountY > 0) moveCountY = 0;

		if(moveCountY < 40) --moveCountY;
		else moveCountY = 0;
	}
	// ���Ɉړ����Ă���
	if (tempMoveY > 0)
	{
		directionState = downDir;

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
		if (tempMoveX < 0 && tempMoveY < 0)
		{
			directionState = upLeftDir;
		}
		if (tempMoveX < 0 && tempMoveY > 0)
		{
			directionState = downLeftDir;
		}
		if (tempMoveX > 0 && tempMoveY < 0)
		{
			directionState = upRightDir;
		}
		if (tempMoveX > 0 && tempMoveY > 0)
		{
			directionState = downRightDir;
		}

		moveIndex = tempMoveIndexX;
	}


	switch (directionState)
	{
	case upDir:
		// �������Ȃ̂ŁA�Q�s�ڂ̐擪�Y�����z��𑫂�
		tempMoveIndexY += moveDivX;
		moveIndex = tempMoveIndexY;

		break;

	case downDir: 
		// ������Ȃ̂ŁA�P�s�ڂ̐擪�Y�����z���result�ɓn��
		moveIndex = tempMoveIndexY;

		break;

	case leftDir: 
		// �������Ȃ̂ŁA�R�s�ڂ̐擪�Y�����z��𑫂�
		tempMoveIndexX += moveDivX * leftDir;
		moveIndex = tempMoveIndexX;

		break;

	case rightDir: 
		// �E�����Ȃ̂ŁA�S�s�ڂ̐擪�Y�����ԍ��𑫂�
		tempMoveIndexX += moveDivX * rightDir;
		moveIndex = tempMoveIndexX;

		break;

	case upLeftDir:
		// �������Ȃ̂ŁA�R�s�ڂ̐擪�Y�����z��𑫂�
		tempMoveIndexX += moveDivX * leftDir;
		moveIndex = tempMoveIndexX;

		break;

	case upRightDir:
		// �E�����Ȃ̂ŁA�S�s�ڂ̐擪�Y�����ԍ��𑫂�
		tempMoveIndexX += moveDivX * rightDir;
		moveIndex = tempMoveIndexX;

		break;

	case downLeftDir:
		// �������Ȃ̂ŁA�R�s�ڂ̐擪�Y�����z��𑫂�
		tempMoveIndexX += moveDivX * leftDir;
		moveIndex = tempMoveIndexX;

		break;
		
	case downRightDir:
		// �E�����Ȃ̂ŁA�S�s�ڂ̐擪�Y�����ԍ��𑫂�
		tempMoveIndexX += moveDivX * rightDir;
		moveIndex = tempMoveIndexX;

		break;
	}

	int t = directionState;

	//DrawFormatString(100, 100, GetColor(255, 0, 0), "direction : %d  x:%d y:%d", t, moveCountX, moveCountY);
	DrawFormatString(100, 100, GetColor(255, 0, 0), "direction : %i", collisionRect);
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
	case downDir:		stopIndex = tempStopIndex;						break;
	case upDir:			stopIndex = tempStopIndex + stopDivX;			break;
	case leftDir:		stopIndex = tempStopIndex + stopDivX * leftDir;	break;
	case rightDir:		stopIndex = tempStopIndex + stopDivX * rightDir;break;
	case upLeftDir:		stopIndex = tempStopIndex + stopDivX * leftDir; break;
	case upRightDir:	stopIndex = tempStopIndex + stopDivX * rightDir; break;
	case downLeftDir:	stopIndex = tempStopIndex + stopDivX * leftDir; break;
	case downRightDir:	stopIndex = tempStopIndex + stopDivX * rightDir; break;
	}
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�����蔻��p�̏���
/////////////////////////////////////////////////////
void Player::Collision(Rect playerRect)
{


	if (playerCollision->OnCollision(playerRect))
	{
		x = memoryX;
		y = memoryY;

		return;
	}

	memoryX = x;
	memoryY = y;
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
	double top	  =  y + 32;
	double bottom =  y + graphSize;
	double left   =  x + 20;
	double right  =  x + graphSize - 20;

	//DrawBox(left, top, right, bottom, GetColor(255, 0, 0), TRUE);

	SetValue(&top, &bottom, &left, &right);
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�^�[�g���̃|�W�V�������Z�b�g
/////////////////////////////////////////////////////
void Player::SetStartPos(double posX, double posY)
{
	x = posX * graphSize + (graphSize / 2);
	y = posY * graphSize + (graphSize / 2);
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

	Rect rect = GetRect();

	//playerCollision->SetPlayerRect(rect);
	RectWatcher::Instance()->SetPlayerRect(rect);
	Collision(rect);
}