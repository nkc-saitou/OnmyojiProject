#include "StageInpoter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "DxLib.h"

StageInpoter::StageInpoter()
{
	// csv�t�@�C���̖��O���擾
	GetFileData(fileNameVec);

	vector<vector<int>> tempStageData;

	for (int i = 0; i < fileNameVec.size(); i++)
	{
		//�@�X�e�[�W�f�[�^�ǂݍ���
		if (IsSplit(fileNameVec[i], tempStageData))
		{
			AssortmentStageData(i, tempStageData);

			stageData.push_back(tempStageData);
			tempStageData.clear();
		}
	}
}

/////////////////////////////////////////////////////
//����			:�t�@�C���S�̂̐��A�P�X�e�[�W���Ƃ̃f�[�^
//�߂�l		:�Ȃ�
//����			:�����I�u�W�F�N�g(��A�v���C���[�A�G)�̍��W���擾
//               �X�e�[�W��񂩂瓮���I�u�W�F�N�g�̏��𕪗�����
/////////////////////////////////////////////////////
void StageInpoter::AssortmentStageData(int num, vector<vector<int>>& stageData)
{
	for (int y = 0; y < stageY; y++)
	{
		// ���̈ʒu���
		vector<position> tempRockPosData;
		vector<position> tempEnemyOnePosData;
		vector<position> tempEnemyTwoPosData;
		
		for (int x = 0; x < stageX; x++)
		{
			position tempPos;
			tempPos.x = x;
			tempPos.y = y;

			// �����ʒu�̏���z��Ɋi�[
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

			// �����I�u�W�F�N�g���������ʒu��empty�Ƃ��ď��������A���������Ă���
			stageData[y][x] = chip_empty;
		}

		rockPosData.push_back(tempRockPosData);
		enemyOnePosData.push_back(tempEnemyOnePosData);
		enemyTwoPosData.push_back(tempEnemyTwoPosData);
	}
}

/////////////////////////////////////////////////////
//����			:�ǂݍ��ރX�e�[�W�f�[�^�̖��O�A�f�[�^�����i�[����z��A�J���}��؂�
//�߂�l		:�t�@�C�����ǂݍ��߂Ă�����true�@�ǂݍ��ݎ��s������false
//����			:csv�̃X�e�[�W�f�[�^��z��Ɋi�[
/////////////////////////////////////////////////////
bool StageInpoter::IsSplit(const string& fileName, vector<vector<int>>& stageData, const char delim)
{
	//�t�@�C�����J��
	fstream file(dataPath + fileName);

	// �t�@�C�����J���Ȃ������ꍇ�͏I��
	if (!file.is_open()) return false;

	while (!file.eof())
	{
		// 1�s�ǂݍ���
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
//����			:�t�@�C�������i�[����string�z��
//�߂�l		:�Ȃ�
//����			:�X�e�[�W�f�[�^�̐��ƃt�@�C�����̎擾
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