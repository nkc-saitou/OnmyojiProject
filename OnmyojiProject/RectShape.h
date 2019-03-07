#pragma once

#include "S_Rect.h"

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

	Rect rect;

protected:
	// �\���̂̒l���X�V
	void SetValue(double *top, double *bottom, double *left, double *right)
	{
		this->rect.top = *top;
		this->rect.bottom = *bottom;
		this->rect.left = *left;
		this->rect.right = *right;
	}

public:
	// �Q�b�^�[
	double GetTop() { return rect.top; }
	double GetBottom() { return rect.bottom; }
	double GetLeft() { return rect.left; }
	double GetRight() { return rect.right; }

	Rect GetRect() { return rect; }

};