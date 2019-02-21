#pragma once

/*
///////////////////////////////////////////
CirclePosition構造体

概要　：円形オブジェクトの各座標が記録されている
使い方：当たり判定を実行する際の引数として与える
///////////////////////////////////////////
*/
struct Circle
{
	int x;
	int y;
	int raddius;
};


/*
///////////////////////////////////////////
CircleShapeクラス

概要　：円の形状を指定するためのクラス
使い方：オブジェクトにそれぞれ継承させて使う。
　　　　コンストラクタでｘ、ｙ、半径をそれぞれ指定する必要あり
///////////////////////////////////////////
*/
class CircleShape
{
public:

	Circle circlePosition;

	void SetValue(double *x, double *y, double *raddius)
	{
		this->circlePosition.x = *x;
		this->circlePosition.y = *y;
		this->circlePosition.raddius = *raddius;
	}

	float GetX() const { return circlePosition.x; }
	float GetY() const { return circlePosition.y; }
	float GetRaddius() const { return circlePosition.raddius; }
};