#pragma once

#include <vector>
#include <string>
#include "Singleton.h"

using namespace std;

/*
///////////////////////////////////////////
position�\����

�T�v�@�F���W���
///////////////////////////////////////////
*/
struct position
{
	double x;
	double y;
};

/*
///////////////////////////////////////////
ChipType�񋓑�

�T�v�@�Fcvs�f�[�^�Ɋ܂܂��`�b�v�f�[�^�����ꂼ���
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
StageInpoter�N���X

�T�v�@�F�X�e�[�W�̓ǂݍ��ݏ���
///////////////////////////////////////////
*/
class StageInpoter :public Singleton <StageInpoter>
{
	//===============================
	// �ϐ�
	//===============================

	// csv�X�e�[�W�f�[�^�̃p�X
	const string dataPath = "../OnmyojiProject/StageData/";

	// �X�e�[�W�f�[�^�̑傫��
	const int stageX = 30;
	const int stageY = 17;

	//unique_ptr<StageCollision> stageCollision = make_unique<StageCollision>();


	// �ǂݍ��݃f�[�^�̖��O
	vector<string> fileNameVec;
	
	// �X�e�[�W�̏��
	vector<vector<vector<int>>> stageData;

	vector<vector<position>> stageCollisionPos;

	// �v���C���[�̏����ʒu
	vector<position> playerPosData;

	// ��̏����ʒu
	vector<vector<position>> rockPosData;

	// �G�̈ʒu
	vector<vector<position>> enemyOnePosData;
	vector<vector<position>> enemyTwoPosData;



	//===============================
	// �֐�
	//===============================

	//�f�[�^��z��Ɋi�[
	bool IsSplit(const string& fileName, vector<vector<int>>& stageData, const char delim = ',');

	void GetFileData(vector<string>& file);

	// �����f�[�^�Ƃ̎d����
	void AssortmentStageData(int num,vector<vector<int>>& stageData);

	vector<position> StageCollisionSet(vector<vector<int>> tempData);

	// �����蔻���t�����(�v���C���[�ƐڐG�̉\��������O���̕�)���ǂ���
	bool IsEdgeCollision(int x, int y , vector<vector<int>> tempData);

	bool IsStageEdge(int x, int y);


public:

	StageInpoter();

	//===============================
	// �Q�b�^�[
	//===============================

	// �X�e�[�W�f�[�^
	vector<vector<vector<int>>> GetStageData(){ return stageData; }

	// �����蔻��p�f�[�^
	vector<vector<position>> GetCollisionData() { return stageCollisionPos; }

	// �v���C���[�̏����|�W�V����
	vector<position> GetPlayerPosData() { return playerPosData; }

	// ��̏����|�W�V����
	vector<vector<position>> GetRockPosData() { return rockPosData; }

	// �G�̏����|�W�V����
	vector<vector<position>> GetEnemyOnePosData() { return enemyOnePosData; }
	vector<vector<position>> GetEnemyTwoPosData() { return enemyTwoPosData; }

	// �X�e�[�W�̐�
	int GetStageCount() { return fileNameVec.size(); }

	// �X�e�[�W�c��
	int GetStageWidth() { return stageX; }
	int GetStageHeight() { return stageY; }
};