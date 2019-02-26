#include "StageInpoter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "DxLib.h"

StageInpoter::StageInpoter()
{
	GetFileData(fileNameVec);

	for (int i = 0; i < fileNameVec.size(); i++)
	{
		//　ステージデータ読み込み
		if (IsSplit(fileNameVec[i], tempStageData) == false) return;

		stageData.push_back(tempStageData);

		tempStageData.clear();
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
	fstream file("../OnmyojiProject/StageData/" + fileName);

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