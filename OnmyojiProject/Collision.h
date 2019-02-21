#pragma once

#include "RectShape.h"
#include "CircleShape.h"
#include "Singleton.h"

/*
///////////////////////////////////////////
Collision�N���X

�T�v�@�F�QD�p�̓����蔻�菈��
�g�����F�I�u�W�F�N�g�ɐݒ肳���Ă���͂��́uRectPosition�v�܂��́uCirclePosition�v��
�@�@�@�@�����ɗ^����B
///////////////////////////////////////////
*/

class Collision : public Singleton <Collision>
{
	// ��`�Ɖ~�`�̓����蔻��p http://ftvoid.com/blog/post/300

	// ���S�_�ƒ����`�̓����蔻��
	bool RectPointAndCircle(const Rect& rect,const Circle& circle);
	// �p�ۂ̓����蔻��
	bool RectVertexAndCircle(const Rect& rect,const Circle& circle);

public:
	// ��`�Ƌ�`
	bool CheckRectAndRect(const Rect& rect1, const Rect& rect2);
	// �~�`�Ɖ~�`
	bool CheckCircleAndCircle(const Circle& circle1, const Circle& circle2);
	// ��`�Ɖ~�`
	bool CheckRectAndCircle(const Rect& rect, const Circle& circle);
	// ��`�Ɠ_
	bool CheckRectAndPoint(const Rect& rect, int x, int y);
};