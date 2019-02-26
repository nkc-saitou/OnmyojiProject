#pragma once

#include <memory>
#include "StageInpoter.h";

using namespace std;

/*
///////////////////////////////////////////
StageDraw�N���X

�T�v�@�F�X�e�[�W�̕`��Ȃ�
�g�����F�I�u�W�F�N�g�ɐݒ肳���Ă���͂��́uRectPosition�v�܂��́uCirclePosition�v��
�@�@�@�@�����ɗ^����B
///////////////////////////////////////////
*/
class StageDraw 
{
	vector<vector<int>> stageData;

	const int stageWidth = StageInpoter::Instance()->StageWidth();
	const int stageHeight = StageInpoter::Instance()->StageHeight();

	void StillDraw();
	void Draw();
	
public:

	void SetStageData(vector<vector<int>> data);

	void Update();
};