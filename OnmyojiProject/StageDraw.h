#pragma once

#include <memory>
#include "StageInpoter.h"

using namespace std;


/*
///////////////////////////////////////////
StageDraw�N���X

�T�v�@�F�X�e�[�W�̕`��Ȃ�
�g�����FSetStageData�̈����ɕ`�悵�����X�e�[�W�f�[�^��n��
///////////////////////////////////////////
*/
class StageDraw 
{
	//===============================
	// �ϐ�
	//===============================
	vector<vector<int>> stageData;

	// �X�e�[�W�T�C�Y
	const int stageWidth = StageInpoter::Instance()->GetStageWidth();
	const int stageHeight = StageInpoter::Instance()->GetStageHeight();


	//===============================
	// �֐�
	//===============================
	// �X�e�[�W�f�[�^(�ǂȂǂ̓����Ȃ�����)��`��
	void StillDraw();

	void Draw();
	
public:

	void Update();


	//===============================
	// �Z�b�^�[
	//===============================

	// �I�����ꂽ�X�e�[�W�����擾����
	void SetStageData(vector<vector<int>> data) { stageData = data; };
};