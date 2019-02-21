#include "Collision.h"


/////////////////////////////////////////////////////
//引数			:矩形と円形の座標情報(rect,circleそれぞれの構造体)
//戻り値		:円の中心点が縦または横に当たっているかどうか。当たっていたらtrue
//動作			:矩形と点の当たり判定。矩形と円形の当たり判定に使う処理
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
//引数			:矩形と円形の座標情報(rect,circleそれぞれの構造体)
//戻り値		:矩形の各頂点と円形の半径の距離が半径以内であればtrue
//動作			:矩形の各頂点と円形の半径の距離を求める。矩形と円形の当たり判定に使う処理
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
//引数			:矩形の座標情報が格納されている構造体
//戻り値		:矩形の要素が、別の矩形の範囲内にあった場合はtrue
//動作			:矩形同士の当たり判定を求める
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
//引数			:円形の座標情報が格納されている構造体
//戻り値		:三平方の定理がなりたてばtrue
//動作			:円形同士の当たり判定を調べる
/////////////////////////////////////////////////////
bool Collision::CheckCircleAndCircle(const Circle& circle1, const Circle& circle2)
{
	// sqrt()関数を使うと処理速度が低下するため、使わない方が良い
	float pow_x = (circle2.x - circle1.x) * (circle2.x - circle1.x);
	float pow_y = (circle2.y - circle1.y) * (circle2.y - circle1.y);

	float pow_raddius = 
		(circle1.raddius + circle2.raddius) *
		(circle1.raddius + circle2.raddius);

	// 三平方の定理
	if (pow_x + pow_y <= pow_raddius)
	{
		return true;
	}
	else return false;
}


/////////////////////////////////////////////////////
//引数			:矩形と円形の座標情報(rect,circleそれぞれの構造体)
//戻り値		:矩形と円形が当たっていればtrue
//動作			:矩形と円形の処理をそれぞれ判定し、どちらかでもtrueだった場合は、
//               矩形と円形は当たっているため、trueとする。
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
//引数			:矩形の座標情報とマウスのポジション
//戻り値		:点が矩形の範囲内にあった場合はtrue
//動作			:矩形の範囲内に点があるかどうかを調べ、フラグを返す。
/////////////////////////////////////////////////////
bool Collision::CheckRectAndPoint(const Rect& rect, int x, int y)
{
	if (rect.top < y && rect.bottom > y && rect.left < x && rect.right > x)
	{
		return true;
	}

	return false;
}