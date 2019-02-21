#pragma once

/*
///////////////////////////////////////////
RectPosition�\����

�T�v�@�F��`�I�u�W�F�N�g�̊e���W���L������
�g�����F�����蔻������s����ۂ̈����Ƃ��ė^����
///////////////////////////////////////////
*/
typedef struct Rect
{
	int top;
	int bottom;
	int left;
	int right;
};

/*
///////////////////////////////////////////
RectShape�N���X

�T�v�@�F��`�̌`����w�肷�邽�߂̃N���X
�g�����F�I�u�W�F�N�g�ɂ��ꂼ��p�������Ďg���B
�@�@�@�@�R���X�g���N�^�ł��A���A���a�����ꂼ��w�肷��K�v����
///////////////////////////////////////////
*/
class RectShape
{
public:
	Rect rect;

	// �\���̂̒l���X�V
	void SetValue(double *top, double *bottom, double *left, double *right)
	{
		this->rect.top = *top;
		this->rect.bottom = *bottom;
		this->rect.left = *left;
		this->rect.right = *right;
	}

	// �Q�b�^�[
	double GetTop()	   const { return rect.top; }
	double GetBottom() const { return rect.bottom; }
	double GetLeft()   const { return rect.left; }
	double GetRight()  const { return rect.right; }

};