#pragma once

#include <vector>
#include <string>
#include "Singleton.h"

using namespace std;

/*
///////////////////////////////////////////
StageInpoter�N���X

�T�v�@�F�X�e�[�W�̓ǂݍ��ݏ���
///////////////////////////////////////////
*/

class StageInpoter :public Singleton <StageInpoter>
{
	//===============================
	// �ϐ�
	//===============================

	// �ǂݍ��݃f�[�^�̖��O
	vector<string> fileNameVec;
	
	vector<vector<vector<int>>> stageData;

	vector<vector<int>> tempStageData;

	const int stageX = 30;
	const int stageY = 17;


	//===============================
	// �֐�
	//===============================

	//�f�[�^��z��Ɋi�[
	bool IsSplit(const string& fileName, vector<vector<int>>& stageData, const char delim = ',');

	void GetFileData(vector<string>& file);


public:

	StageInpoter();

	//===============================
	// �v���p�e�B
	//===============================

	// �X�e�[�W�f�[�^�@�Q�b�^�[
	vector<vector<vector<int>>> GetStageData(){ return stageData; }

	// �X�e�[�W�̐�
	int StageCount() { return fileNameVec.size(); }

	int StageWidth() { return stageX; }
	int StageHeight() { return stageY; }
};