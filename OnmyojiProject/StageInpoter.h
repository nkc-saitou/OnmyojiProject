#pragma once

#include <vector>
#include <string>
#include "Singleton.h"

using namespace std;

/*
///////////////////////////////////////////
StageInpoterクラス

概要　：ステージの読み込み処理
///////////////////////////////////////////
*/

class StageInpoter :public Singleton <StageInpoter>
{
	//===============================
	// 変数
	//===============================

	// 読み込みデータの名前
	vector<string> fileNameVec;
	
	vector<vector<vector<int>>> stageData;

	vector<vector<int>> tempStageData;

	const int stageX = 30;
	const int stageY = 17;


	//===============================
	// 関数
	//===============================

	//データを配列に格納
	bool IsSplit(const string& fileName, vector<vector<int>>& stageData, const char delim = ',');

	void GetFileData(vector<string>& file);


public:

	StageInpoter();

	//===============================
	// プロパティ
	//===============================

	// ステージデータ　ゲッター
	vector<vector<vector<int>>> GetStageData(){ return stageData; }

	// ステージの数
	int StageCount() { return fileNameVec.size(); }

	int StageWidth() { return stageX; }
	int StageHeight() { return stageY; }
};