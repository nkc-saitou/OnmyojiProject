#pragma once

#include <vector>
#include <string>
#include "Singleton.h"

using namespace std;

/*
///////////////////////////////////////////
position構造体

概要　：座標情報
///////////////////////////////////////////
*/
struct position
{
	double x;
	double y;
};

/*
///////////////////////////////////////////
ChipType列挙隊

概要　：cvsデータに含まれるチップデータをそれぞれ列挙
///////////////////////////////////////////
*/
enum ChipType
{
	chip_empty = 0,
	chip_still,
	chip_rock,
	chip_playerStartPos,
	chip_enemy_one_StartPos,
	chip_enemy_two_StartPos,
	chip_ster_one,
	chip_star_two,
	chip_star_three,
	chip_star_four,
	chip_star_five
};

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

	// csvステージデータのパス
	const string dataPath = "../OnmyojiProject/StageData/";

	// ステージデータの大きさ
	const int stageX = 30;
	const int stageY = 17;

	//unique_ptr<StageCollision> stageCollision = make_unique<StageCollision>();


	// 読み込みデータの名前
	vector<string> fileNameVec;
	
	// ステージの情報
	vector<vector<vector<int>>> stageData;

	vector<vector<position>> stageCollisionPos;

	// プレイヤーの初期位置
	vector<position> playerPosData;

	// 岩の初期位置
	vector<vector<position>> rockPosData;

	// 敵の位置
	vector<vector<position>> enemyOnePosData;
	vector<vector<position>> enemyTwoPosData;



	//===============================
	// 関数
	//===============================

	//データを配列に格納
	bool IsSplit(const string& fileName, vector<vector<int>>& stageData, const char delim = ',');

	void GetFileData(vector<string>& file);

	// 動くデータとの仕分け
	void AssortmentStageData(int num,vector<vector<int>>& stageData);

	vector<position> StageCollisionSet(vector<vector<int>> tempData);

	// 当たり判定を付ける壁(プレイヤーと接触の可能性がある外側の壁)かどうか
	bool IsEdgeCollision(int x, int y , vector<vector<int>> tempData);

	bool IsStageEdge(int x, int y);


public:

	StageInpoter();

	//===============================
	// ゲッター
	//===============================

	// ステージデータ
	vector<vector<vector<int>>> GetStageData(){ return stageData; }

	// 当たり判定用データ
	vector<vector<position>> GetCollisionData() { return stageCollisionPos; }

	// プレイヤーの初期ポジション
	vector<position> GetPlayerPosData() { return playerPosData; }

	// 岩の初期ポジション
	vector<vector<position>> GetRockPosData() { return rockPosData; }

	// 敵の初期ポジション
	vector<vector<position>> GetEnemyOnePosData() { return enemyOnePosData; }
	vector<vector<position>> GetEnemyTwoPosData() { return enemyTwoPosData; }

	// ステージの数
	int GetStageCount() { return fileNameVec.size(); }

	// ステージ縦横
	int GetStageWidth() { return stageX; }
	int GetStageHeight() { return stageY; }
};