#pragma once

#include <memory>
#include "StageInpoter.h"
#include "E_SceneState.h"

using namespace std;

/*
///////////////////////////////////////////
StageDrawクラス

概要　：ステージの描画など
使い方：SetStageDataの引数に描画したいステージデータを渡す
///////////////////////////////////////////
*/
class StageDraw 
{
	//===============================
	// 変数
	//===============================
	vector<vector<int>> stageData;

	// ステージサイズ
	const int stageWidth = StageInpoter::Instance()->GetStageWidth();
	const int stageHeight = StageInpoter::Instance()->GetStageHeight();

	SceneState sceneState;

	//===============================
	// 関数
	//===============================
	// ステージデータ(壁などの動かないもの)を描画
	void StillDraw();

	void Draw();
	
public:

	StageDraw(SceneState state);

	void Update();


	//===============================
	// セッター
	//===============================

	// 選択されたステージ情報を取得する
	void SetStageData(vector<vector<int>> data) { stageData = data; };
};