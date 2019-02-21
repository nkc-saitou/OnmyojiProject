#pragma once

#include "RectShape.h"
#include "CircleShape.h"
#include "Singleton.h"

/*
///////////////////////////////////////////
Collisionクラス

概要　：２D用の当たり判定処理
使い方：オブジェクトに設定させてあるはずの「RectPosition」または「CirclePosition」を
　　　　引数に与える。
///////////////////////////////////////////
*/

class Collision : public Singleton <Collision>
{
	// 矩形と円形の当たり判定用 http://ftvoid.com/blog/post/300

	// 中心点と長方形の当たり判定
	bool RectPointAndCircle(const Rect& rect,const Circle& circle);
	// 角丸の当たり判定
	bool RectVertexAndCircle(const Rect& rect,const Circle& circle);

public:
	// 矩形と矩形
	bool CheckRectAndRect(const Rect& rect1, const Rect& rect2);
	// 円形と円形
	bool CheckCircleAndCircle(const Circle& circle1, const Circle& circle2);
	// 矩形と円形
	bool CheckRectAndCircle(const Rect& rect, const Circle& circle);
	// 矩形と点
	bool CheckRectAndPoint(const Rect& rect, int x, int y);
};