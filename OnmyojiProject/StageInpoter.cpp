#include "StageInpoter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "DxLib.h"

using namespace std;

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�f�[�^�ǂݍ���
/////////////////////////////////////////////////////
StageInpoter::StageInpoter()
{
	// csv�t�@�C���̖��O���擾
	GetFileData(fileNameVec);

	vector<vector<int>> tempStageData;

	for (int i = 0; i < fileNameVec.size(); i++)
	{
		// �ꎞ�I�ɒl���i�[���Ă����z��
		vector<position> tempStageCollisionPos;
		vector<position> tempGoalStarPos;

		//�@�X�e�[�W�f�[�^�ǂݍ���
		if (IsSplit(fileNameVec[i], tempStageData))
		{
			// �X�e�[�W�f�[�^�̎d����
			//(�����Ȃ��ǂ̂݃X�e�[�W�f�[�^�Ɏc���A��͕ʂő��̔z��ɕۑ����Ă���)
			AssortmentStageData(i, tempStageData);

			// �X�e�[�W�f�[�^��ۑ�
			stageData.push_back(tempStageData);

			// �����蔻��f�[�^�̕ۑ�
			tempStageCollisionPos = StageCollisionSet(tempStageData);

			// �S�[���ʒu�̕ۑ�
			tempGoalStarPos = StageStarPosSet(tempStageData);

			// �z��̏�����
			tempStageData.clear();
		}

		// �f�[�^���i�[
		stageCollisionPos.push_back(tempStageCollisionPos);
		goalStarPosData.push_back(tempGoalStarPos);
	}
}

/////////////////////////////////////////////////////
//����			:�f�[�^�`�b�v���̔z��
//�߂�l		:�`�b�v�̍��W
//����			:�����蔻��p�̓����Ȃ��ǂ̍��W���擾
/////////////////////////////////////////////////////
vector<position> StageInpoter::StageCollisionSet(vector<vector<int>> tempData)
{
	// �����Ȃ��ǂ̍��W���ꎞ�I�ɕۑ����Ă���
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
//����			:�f�[�^�`�b�v���̔z��
//�߂�l		:�X�^�[(�S�[��)�̈ʒu
//����			:�X�^�[(�S�[��)�̈ʒu��z��Ɋi�[
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
//����			:�z��̓Y�������A���A�`�b�v�f�[�^���
//�߂�l		:�����蔻��𒲂ׂ��(�X�e�[�W�̒[�ł͂Ȃ� ���� �����ɖ��܂��Ă���ǂł͂Ȃ�)��������true
//����			:�����蔻��𒲂ׂ�ǂƂ����łȂ��ǂ�I�ʂ���
/////////////////////////////////////////////////////
bool StageInpoter::IsEdgeCollision(int x, int y, vector<vector<int>> tempData)
{
	// �����Ȃ��ǈȊO�̓����蔻��͂����ł͍l���Ȃ�
	if (tempData[y][x] != chip_still) return false;

	// �X�e�[�W�[�͕ς�邱�Ƃ��Ȃ����߁A�[�̓����蔻��͂����ł͍l���Ȃ�
	if (IsStageEdge(x, y) == true) return false;

	// �����ǂň͂܂ꂽ�����蔻��ɂ��ẮA�����ݒ肷��K�v�͂Ȃ�
	if (tempData[y][x + 1] == chip_still && tempData[y][x - 1] == chip_still &&
		tempData[y + 1][x] == chip_still && tempData[y - 1][x] == chip_still)
		return false;

	// ����ȊO�̕ǂ͓����蔻���ݒ肷��
	return true;
}

/////////////////////////////////////////////////////
//����			:�z��̓Y�����ԍ�x,y
//�߂�l		:�X�e�[�W�[�ł�������true
//����			:���݂̈ʒu���X�e�[�W�[�Ɉʒu���邩�ǂ���
/////////////////////////////////////////////////////
bool StageInpoter::IsStageEdge(int x, int y)
{
	if (y == 0 || y >= stageY - 1 || x == 0 || x >= stageX - 1) return true;
	else return false;
}

/////////////////////////////////////////////////////
//����			:�t�@�C���S�̂̐��A�P�X�e�[�W���Ƃ̃f�[�^
//�߂�l		:�Ȃ�
//����			:�����I�u�W�F�N�g(��A�v���C���[�A�G)�̍��W���擾
//               �X�e�[�W��񂩂瓮���I�u�W�F�N�g�̏��𕪗�����
/////////////////////////////////////////////////////
void StageInpoter::AssortmentStageData(int num, vector<vector<int>>& stageData)
{
	// ���̈ʒu���
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

	}

	if (tempRockPosData.size() != 0) rockPosData.push_back(tempRockPosData);
	if (tempEnemyOnePosData.size() != 0) enemyOnePosData.push_back(tempEnemyOnePosData);
	if (tempEnemyTwoPosData.size() != 0) enemyTwoPosData.push_back(tempEnemyTwoPosData);
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