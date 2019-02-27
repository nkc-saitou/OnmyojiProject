#include "StageInpoter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "DxLib.h"

StageInpoter::StageInpoter()
{
	// csvファイルの名前を取得
	GetFileData(fileNameVec);

	vector<vector<int>> tempStageData;

	for (int i = 0; i < fileNameVec.size(); i++)
	{
		//　ステージデータ読み込み
		if (IsSplit(fileNameVec[i], tempStageData))
		{
			AssortmentStageData(i, tempStageData);

			stageData.push_back(tempStageData);
			tempStageData.clear();
		}
	}
}

/////////////////////////////////////////////////////
//引数			:ファイル全体の数、１ステージごとのデータ
//戻り値		:なし
//動作			:動くオブジェクト(岩、プレイヤー、敵)の座標を取得
//               ステージ情報から動くオブジェクトの情報を分離する
/////////////////////////////////////////////////////
void StageInpoter::AssortmentStageData(int num, vector<vector<int>>& stageData)
{
	for (int y = 0; y < stageY; y++)
	{
		// 仮の位置情報
		vector<position> tempRockPosData;
		vector<position> tempEnemyOnePosData;
		vector<position> tempEnemyTwoPosData;
		
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

		rockPosData.push_back(tempRockPosData);
		enemyOnePosData.push_back(tempEnemyOnePosData);
		enemyTwoPosData.push_back(tempEnemyTwoPosData);
	}
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