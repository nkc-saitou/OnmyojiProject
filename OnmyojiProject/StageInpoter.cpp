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
		//�@�X�e�[�W�f�[�^�ǂݍ���
		if (IsSplit(fileNameVec[i], tempStageData) == false) return;

		stageData.push_back(tempStageData);

		tempStageData.clear();
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
	fstream file("../OnmyojiProject/StageData/" + fileName);

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