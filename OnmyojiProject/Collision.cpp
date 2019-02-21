#include "Collision.h"


/////////////////////////////////////////////////////
//����			:��`�Ɖ~�`�̍��W���(rect,circle���ꂼ��̍\����)
//�߂�l		:�~�̒��S�_���c�܂��͉��ɓ������Ă��邩�ǂ����B�������Ă�����true
//����			:��`�Ɠ_�̓����蔻��B��`�Ɖ~�`�̓����蔻��Ɏg������
/////////////////////////////////////////////////////
bool Collision::RectPointAndCircle(const Rect& rect, const Circle& circle)
{
	if ((circle.x > rect.left) && (circle.x < rect.right) &&
		(circle.y > rect.top - circle.raddius) && (circle.y < rect.bottom + circle.raddius))
	{
		return true;
	}
	else if ((circle.x > rect.left - circle.raddius) && (circle.x < rect.right + circle.raddius) &&
		(circle.y > rect.top) && (circle.y < rect.bottom))
	{
		return true;
	}
	else return false;
}

/////////////////////////////////////////////////////
//����			:��`�Ɖ~�`�̍��W���(rect,circle���ꂼ��̍\����)
//�߂�l		:��`�̊e���_�Ɖ~�`�̔��a�̋��������a�ȓ��ł����true
//����			:��`�̊e���_�Ɖ~�`�̔��a�̋��������߂�B��`�Ɖ~�`�̓����蔻��Ɏg������
/////////////////////////////////////////////////////

bool Collision::RectVertexAndCircle(const Rect& rect, const Circle& circle)
{
	int rectLeftPow = (rect.left - circle.x) * (rect.left - circle.x);
	int rectRightPow = (rect.right - circle.x) * (rect.right - circle.x);
	int rectTopPow = (rect.top - circle.y) * (rect.top - circle.y);
	int rectBottomPow = (rect.bottom - circle.y) * (rect.bottom - circle.y);

	int raddiusPow = circle.raddius * circle.raddius;

	if (rectLeftPow + rectTopPow < raddiusPow || rectRightPow + rectTopPow < raddiusPow ||
		rectRightPow + rectBottomPow < raddiusPow || rectLeftPow + rectBottomPow < raddiusPow)
	{
		return true;
	}
	else return false;
}

/////////////////////////////////////////////////////
//����			:��`�̍��W��񂪊i�[����Ă���\����
//�߂�l		:��`�̗v�f���A�ʂ̋�`�͈͓̔��ɂ������ꍇ��true
//����			:��`���m�̓����蔻������߂�
/////////////////////////////////////////////////////
bool Collision::CheckRectAndRect(const Rect& rect1, const Rect& rect2)
{
	if (rect1.right >= rect2.left && rect1.left <= rect2.right)
	{
		if (rect1.bottom >= rect2.top && rect1.top <= rect2.bottom)
		{
			return true;
		}
	}
	return false;
}

/////////////////////////////////////////////////////
//����			:�~�`�̍��W��񂪊i�[����Ă���\����
//�߂�l		:�O�����̒藝���Ȃ肽�Ă�true
//����			:�~�`���m�̓����蔻��𒲂ׂ�
/////////////////////////////////////////////////////
bool Collision::CheckCircleAndCircle(const Circle& circle1, const Circle& circle2)
{
	// sqrt()�֐����g���Ə������x���ቺ���邽�߁A�g��Ȃ������ǂ�
	float pow_x = (circle2.x - circle1.x) * (circle2.x - circle1.x);
	float pow_y = (circle2.y - circle1.y) * (circle2.y - circle1.y);

	float pow_raddius = 
		(circle1.raddius + circle2.raddius) *
		(circle1.raddius + circle2.raddius);

	// �O�����̒藝
	if (pow_x + pow_y <= pow_raddius)
	{
		return true;
	}
	else return false;
}


/////////////////////////////////////////////////////
//����			:��`�Ɖ~�`�̍��W���(rect,circle���ꂼ��̍\����)
//�߂�l		:��`�Ɖ~�`���������Ă����true
//����			:��`�Ɖ~�`�̏��������ꂼ�ꔻ�肵�A�ǂ��炩�ł�true�������ꍇ�́A
//               ��`�Ɖ~�`�͓������Ă��邽�߁Atrue�Ƃ���B
/////////////////////////////////////////////////////
bool Collision::CheckRectAndCircle(const Rect& rect, const Circle& circle)
{
	// http://ftvoid.com/blog/post/300

	if (RectPointAndCircle(rect, circle) || RectVertexAndCircle(rect, circle))
	{
		return true;
	}

	return false;
}

/////////////////////////////////////////////////////
//����			:��`�̍��W���ƃ}�E�X�̃|�W�V����
//�߂�l		:�_����`�͈͓̔��ɂ������ꍇ��true
//����			:��`�͈͓̔��ɓ_�����邩�ǂ����𒲂ׁA�t���O��Ԃ��B
/////////////////////////////////////////////////////
bool Collision::CheckRectAndPoint(const Rect& rect, int x, int y)
{
	if (rect.top < y && rect.bottom > y && rect.left < x && rect.right > x)
	{
		return true;
	}

	return false;
}