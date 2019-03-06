#pragma once

#include <vector>
#include <string>
#include "Singleton.h"

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
	const std::string dataPath = "../OnmyojiProject/StageData/";

	// �X�e�[�W�f�[�^�̑傫��
	const int stageX = 30;
	const int stageY = 17;

	//unique_ptr<StageCollision> stageCollision = make_unique<StageCollision>();


	// �ǂݍ��݃f�[�^�̖��O
	std::vector<std::string> fileNameVec;
	
	// �X�e�[�W�̏��
	std::vector<std::vector<std::vector<int>>> stageData;

	std::vector<std::vector<position>> stageCollisionPos;

	// �v���C���[�̏����ʒu
	std::vector<position> playerPosData;

	// ��̏����ʒu
	std::vector<std::vector<position>> rockPosData;

	// �G�̈ʒu
	std::vector<std::vector<position>> enemyOnePosData;
	std::vector<std::vector<position>> enemyTwoPosData;



	//===============================
	// �֐�
	//===============================

	//�f�[�^��z��Ɋi�[
	bool IsSplit(const std::string& fileName, std::vector<std::vector<int>>& stageData, const char delim = ',');

	void GetFileData(std::vector<std::string>& file);

	// �����f�[�^�Ƃ̎d����
	void AssortmentStageData(int num, std::vector<std::vector<int>>& stageData);

	std::vector<position> StageCollisionSet(std::vector<std::vector<int>> tempData);

	// �����蔻���t�����(�v���C���[�ƐڐG�̉\��������O���̕�)���ǂ���
	bool IsEdgeCollision(int x, int y , std::vector<std::vector<int>> tempData);

	bool IsStageEdge(int x, int y);


public:

	StageInpoter();

	//===============================
	// �Q�b�^�[
	//===============================

	// �X�e�[�W�f�[�^
	std::vector<std::vector<std::vector<int>>> GetStageData(){ return stageData; }

	// �����蔻��p�f�[�^
	std::vector<std::vector<position>> GetStageCollisionData() { return stageCollisionPos; }

	// �v���C���[�̏����|�W�V����
	std::vector<position> GetPlayerPosData() { return playerPosData; }

	// ��̏����|�W�V����
	std::vector<std::vector<position>> GetRockPosData() { return rockPosData; }

	// �G�̏����|�W�V����
	std::vector<std::vector<position>> GetEnemyOnePosData() { return enemyOnePosData; }
	std::vector<std::vector<position>> GetEnemyTwoPosData() { return enemyTwoPosData; }

	// �X�e�[�W�̐�
	int GetStageCount() { return fileNameVec.size(); }

	// �X�e�[�W�c��
	int GetStageWidth() { return stageX; }
	int GetStageHeight() { return stageY; }
};