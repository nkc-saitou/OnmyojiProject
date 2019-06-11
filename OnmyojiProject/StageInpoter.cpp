#include "StageInpoter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "DxLib.h"

using namespace std;

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:データ読み込み
/////////////////////////////////////////////////////
StageInpoter::StageInpoter()
{
	// csvファイルの名前を取得
	GetFileData(fileNameVec);

	vector<vector<int>> tempStageData;

	for (int i = 0; i < fileNameVec.size(); i++)
	{
		// 一時的に値を格納しておく配列
		vector<position> tempStageCollisionPos;
		vector<position> tempGoalStarPos;

		//　ステージデータ読み込み
		if (IsSplit(fileNameVec[i], tempStageData))
		{
			// ステージデータの仕分け
			//(動かない壁のみステージデータに残し、後は別で他の配列に保存しておく)
			AssortmentStageData(i, tempStageData);

			// ステージデータを保存
			stageData.push_back(tempStageData);

			// 当たり判定データの保存
			tempStageCollisionPos = StageCollisionSet(tempStageData);

			// ゴール位置の保存
			tempGoalStarPos = StageStarPosSet(tempStageData);

			// 配列の初期化
			tempStageData.clear();
		}

		// データを格納
		stageCollisionPos.push_back(tempStageCollisionPos);
		goalStarPosData.push_back(tempGoalStarPos);
	}
}

/////////////////////////////////////////////////////
//引数			:データチップ情報の配列
//戻り値		:チップの座標
//動作			:当たり判定用の動かない壁の座標を取得
/////////////////////////////////////////////////////
vector<position> StageInpoter::StageCollisionSet(vector<vector<int>> tempData)
{
	// 動かない壁の座標を一時的に保存しておく
	vector<position> tempStageCollisionPos;

	for (int i = 0; i < tempData.size(); i++)
	{
		for (int j = 0; j < tempData[i].size(); j++)
		{
			if (IsEdgeCollision(j, i,tempData))
			{
				position tempPos;
				tempPos.x = j;
				tempPos.y = i;

				tempStageCollisionPos.push_back(tempPos);
			}
		}
	}

	return tempStageCollisionPos;
}

/////////////////////////////////////////////////////
//引数			:データチップ情報の配列
//戻り値		:スター(ゴール)の位置
//動作			:スター(ゴール)の位置を配列に格納
/////////////////////////////////////////////////////
std::vector<position> StageInpoter::StageStarPosSet(std::vector<std::vector<int>> tempData)
{
	vector<position> tempGoalStarPosData;

	for (int i = 0; i < tempData.size(); i++)
	{
		for (int j = 0; j < tempData[i].size(); j++)
		{
			if (tempData[i][j] == chip_star)
			{
				position tempPos;
				tempPos.x = j;
				tempPos.y = i;

				tempGoalStarPosData.push_back(tempPos);
			}
		}
	}

	return tempGoalStarPosData;
}

/////////////////////////////////////////////////////
//引数			:配列の添え字ｘ、ｙ、チップデータ情報
//戻り値		:当たり判定を調べる壁(ステージの端ではない かつ 内側に埋まっている壁ではない)だったらtrue
//動作			:当たり判定を調べる壁とそうでない壁を選別する
/////////////////////////////////////////////////////
bool StageInpoter::IsEdgeCollision(int x, int y, vector<vector<int>> tempData)
{
	// 動かない壁以外の当たり判定はここでは考えない
	if (tempData[y][x] != chip_still) return false;

	// ステージ端は変わることがないため、端の当たり判定はここでは考えない
	if (IsStageEdge(x, y) == true) return false;

	// 周りを壁で囲まれた当たり判定については、判定を設定する必要はない
	if (tempData[y][x + 1] == chip_still && tempData[y][x - 1] == chip_still &&
		tempData[y + 1][x] == chip_still && tempData[y - 1][x] == chip_still)
		return false;

	// それ以外の壁は当たり判定を設定する
	return true;
}

/////////////////////////////////////////////////////
//引数			:配列の添え字番号x,y
//戻り値		:ステージ端であったらtrue
//動作			:現在の位置がステージ端に位置するかどうか
/////////////////////////////////////////////////////
bool StageInpoter::IsStageEdge(int x, int y)
{
	if (y == 0 || y >= stageY - 1 || x == 0 || x >= stageX - 1) return true;
	else return false;
}

/////////////////////////////////////////////////////
//引数			:ファイル全体の数、１ステージごとのデータ
//戻り値		:なし
//動作			:動くオブジェクト(岩、プレイヤー、敵)の座標を取得
//               ステージ情報から動くオブジェクトの情報を分離する
/////////////////////////////////////////////////////
void StageInpoter::AssortmentStageData(int num, vector<vector<int>>& stageData)
{
	// 仮の位置情報
	vector<position> tempRockPosData;
	vector<position> tempEnemyOnePosData;
	vector<position> tempEnemyTwoPosData;

	for (int y = 0; y < stageY; y++)
	{
		for (int x = 0; x < stageX; x++)
		{
			position tempPos;
			tempPos.x = x;
			tempPos.y = y;

			// 初期位置の情報を配列に格納
			switch (stageData[y][x])
			{
			case chip_rock:
				tempRockPosData.push_back(tempPos);
				break;

			case chip_playerStartPos:
				playerPosData.push_back(tempPos);
				break;

			case chip_enemy_one_StartPos:
				tempEnemyOnePosData.push_back(tempPos);
				break;

			case chip_enemy_two_StartPos:
				tempEnemyTwoPosData.push_back(tempPos);
				break;

			default: continue;
			}

			// 動くオブジェクトがあった位置はemptyとして書き換え、分離させておく
			stageData[y][x] = chip_empty;
		}

	}

	if (tempRockPosData.size() != 0) rockPosData.push_back(tempRockPosData);
	if (tempEnemyOnePosData.size() != 0) enemyOnePosData.push_back(tempEnemyOnePosData);
	if (tempEnemyTwoPosData.size() != 0) enemyTwoPosData.push_back(tempEnemyTwoPosData);
}

/////////////////////////////////////////////////////
//引数			:読み込むステージデータの名前、データ情報を格納する配列、カンマ区切り
//戻り値		:ファイルが読み込めていたらtrue　読み込み失敗したらfalse
//動作			:csvのステージデータを配列に格納
/////////////////////////////////////////////////////
bool StageInpoter::IsSplit(const string& fileName, vector<vector<int>>& stageData, const char delim)
{
	//ファイルを開く
	fstream file(dataPath + fileName);

	// ファイルが開けなかった場合は終了
	if (!file.is_open()) return false;

	while (!file.eof())
	{
		// 1行読み込む
		string buffer;
		file >> buffer;

		vector<int> record;
		istringstream streamBuffer(buffer);
		string token;

		token = token.substr(0, token.find_last_not_of(' ') + 1);

		while (getline(streamBuffer, token, delim))
		{
			record.push_back(atoi(token.c_str()));
		}

		stageData.push_back(record);
	}

	return true;
}

/////////////////////////////////////////////////////
//引数			:ファイル名を格納するstring配列
//戻り値		:なし
//動作			:ステージデータの数とファイル名の取得
/////////////////////////////////////////////////////
void StageInpoter::GetFileData(vector<string>& file)
{
	HANDLE hFind;

	WIN32_FIND_DATA win32fd;

	hFind = FindFirstFile("../OnmyojiProject/StageData/*.csv", &win32fd);

	if (hFind == INVALID_HANDLE_VALUE) return;
	
	do {

		if ((win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) 
		{
			file.push_back(win32fd.cFileName);
		}

	} while (FindNextFile(hFind, &win32fd));

	FindClose(hFind);
}