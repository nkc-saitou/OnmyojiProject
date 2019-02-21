#pragma once

#include "RectShape.h"
#include "Collision.h"
#include <memory>
#include <vector>

using namespace std;

struct ChipPosition
{
	int drawPosX;
	int drawPosY;
};

class StageEditor
{
	//�X�N���[���T�C�Y
	const int screenScaleX = 1920;
	const int screenScaleY = 1080;

	// �C���[�W�̃T�C�Y
	const int mapChipGraphSize = 32;
	const int selectMapChipGraphSize = 128;

	// �C���[�W�S�̂̕�����
	const int allDivision = 7;

	// ���̕�����
	const int divisionX = 7;

	// �c�̕�����
	const int divisionY = 1;

	// �}�b�v�G�f�B�^�S�̂̔z�u�n�_
	const int mapEditorPosX = screenScaleX / 3;
	const int mapEditorPosY = screenScaleY / 3;

	// �}�b�v�`�b�v�̉摜�z��̓Y��
	int chipIndex = 0;

	// �}�b�v�`�b�v�̃O���t�B�b�N�n���h��
	int chipGh[7];

	// �}�E�X�ʒu�̎擾
	int mousePosX, mousePosY;

	// �}�b�v�`�b�v���c���ɂ��ꂼ��z�u���鐔
	double mapNumX = screenScaleX / 64;
	double mapNumY = screenScaleY / 64;

	// �e�}�X�ɉ����u����Ă��邩���L������f�[�^�z��
	vector<vector<int>> mapStageData = vector<vector<int>>();

	// �}�b�v�`�b�v�Ƃ��Ĕz�u����摜�T�C�Y���㉺���E�Ŏ擾
	vector<vector<Rect>> chipRectPosVec = vector<vector<Rect>>();
	// �}�b�v�`�b�v�Ƃ��Ĕz�u����摜�̈ʒu�����擾
	vector<vector<ChipPosition>> chipPosVec = vector<vector<ChipPosition>>();

	// �}�b�v�`�b�v��I������p�̃I�u�W�F�N�g�̉摜�T�C�Y���㉺���E�Ŏ擾
	vector<Rect> selectChipRectPosVec = vector<Rect>();
	// �I������p�̉摜�̈ʒu�����擾
	vector<ChipPosition> selectChipPosVec = vector<ChipPosition>();



	//===============================
	// �֐�
	//===============================

	Rect GetChipRectPos(int x, int y);
	ChipPosition GetChipCenterPos(int x, int y);

	void SetMapChipPlacePos();
	void SetSelectMapChipPlacePos();
	void ExportStage();
	void ChangeMapChip(int x, int y, int chipInde, Rect chipRectPos);
	void MapChipDraw();
	void SelectMapChipDraw();

	bool IsRectMouseOver(Rect chipRectPos);
	bool IsRectClick(Rect chipRectPos);
	bool IsRectEdge(int x, int y);

public:
	StageEditor();
	void Draw();
	void Update();
};