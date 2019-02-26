#pragma once

#include <memory>
#include "StageInpoter.h";

using namespace std;

/*
///////////////////////////////////////////
StageDrawクラス

概要　：ステージの描画など
使い方：オブジェクトに設定させてあるはずの「RectPosition」または「CirclePosition」を
　　　　引数に与える。
///////////////////////////////////////////
*/
class StageDraw 
{
	vector<vector<int>> stageData;

	const int stageWidth = StageInpoter::Instance()->StageWidth();
	const int stageHeight = StageInpoter::Instance()->StageHeight();

	void StillDraw();
	void Draw();
	
public:

	void SetStageData(vector<vector<int>> data);

	void Update();
};