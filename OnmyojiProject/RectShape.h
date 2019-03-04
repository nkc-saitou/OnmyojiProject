#pragma once

/*
///////////////////////////////////////////
RectPosition構造体

概要　：矩形オブジェクトの各座標を記憶する
使い方：当たり判定を実行する際の引数として与える
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
RectShapeクラス

概要　：矩形の形状を指定するためのクラス
使い方：オブジェクトにそれぞれ継承させて使う。
　　　　コンストラクタでｘ、ｙ、半径をそれぞれ指定する必要あり
///////////////////////////////////////////
*/
class RectShape
{

	Rect rect;


protected:
	// 構造体の値を更新
	void SetValue(double *top, double *bottom, double *left, double *right)
	{
		this->rect.top = *top;
		this->rect.bottom = *bottom;
		this->rect.left = *left;
		this->rect.right = *right;
	}

public:
	// ゲッター
	double GetTop() { return rect.top; }
	double GetBottom() { return rect.bottom; }
	double GetLeft() { return rect.left; }
	double GetRight() { return rect.right; }

	Rect GetRect() { return rect; }

};