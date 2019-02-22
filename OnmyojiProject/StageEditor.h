#pragma once

#include "RectShape.h"
#include "Collision.h"
#include <memory>
#include <vector>


/*
///////////////////////////////////////////
ChipPosition

�T�v�@�F�`�b�v��̍��W�����i�[
///////////////////////////////////////////
*/
struct ChipPosition
{
	int drawPosX;
	int drawPosY;
};

enum ClickState
{
	leftClick = 0,
	rightClick,
	anyClick,
};

/*
///////////////////////////////////////////
StageEditor�N���X

�T�v�@�F�X�e�[�W�G�f�B�^�[
///////////////////////////////////////////
*/
using namespace std;

class StageEditor
{
	//�X�N���[���T�C�Y
	const int screenScaleX = 1920;
	const int screenScaleY = 1080;

	// �C���[�W�̃T�C�Y
	const int mapChipGraphSize = 32;
	const int selectMapChipGraphSize = 128;

	// �C���[�W�S�̂̕�����
	const int allDivision = 11;

	// ���̕�����
	const int divisionX = 6;

	// �c�̕�����
	const int divisionY = 2;

	// �}�b�v�`�b�v���c�����ꂼ��z�u���鐔
	const int mapNumX = 30;
	const int mapNumY = 16;

	// �I��p�̃}�b�v�`�b�v��z�u���鐔
	const int selectChipNum = 5;

	// �}�b�v�G�f�B�^�S�̂̔z�u�n�_
	const int mapEditorPosX = screenScaleX / 3;
	const int mapEditorPosY = screenScaleY / 3;

	// �}�b�v�`�b�v�̉摜�z��̓Y��
	int chipIndex = 0;

	// �}�b�v�`�b�v�̃O���t�B�b�N�n���h��
	int chipGh[11];
	int backGroundGh;

	// �}�E�X�ʒu�̎擾
	int mousePosX, mousePosY;

	// �`�F���W����ۂ̈ړ��O�}�b�v�ʒu
	int changinMapX, changinMapY;
	// �`�F���W����ۂ̈ړ��O�̃`�b�v�̎��
	int changinChipIndex;

	int resetChangeTimer;

	// �}�b�v���������Ă���Œ����ǂ���
	bool isChipChanging = false;

	bool isResetChipChange = false;

	ClickState state;

	// �e�}�X�ɉ����u����Ă��邩���L������f�[�^�z��
	vector<vector<int>> mapStageData;

	// �}�b�v�`�b�v�Ƃ��Ĕz�u����摜�T�C�Y���㉺���E�Ŏ擾
	vector<vector<Rect>> chipRectPosVec;
	// �}�b�v�`�b�v�Ƃ��Ĕz�u����摜�̈ʒu�����擾
	vector<vector<ChipPosition>> chipPosVec ;

	// �}�b�v�`�b�v��I������p�̃I�u�W�F�N�g�̉摜�T�C�Y���㉺���E�Ŏ擾
	vector<Rect> selectChipRectPosVec;
	// �I������p�̉摜�̈ʒu�����擾
	vector<ChipPosition> selectChipPosVec;


	//===============================
	// �֐�
	//===============================

	// �}�b�v�`�b�v�̏㉺���E�̍��W�����擾
	Rect GetChipRect(int x, int y);
	// �}�b�v�`�b�v�̈ʒu�����擾
	ChipPosition GetChipPos(int x, int y);

	// �G�f�B�^�[�̔z�u�ʒu���Z�b�g����
	void SetEditorPlacePos();
	// �}�b�v�`�b�v�I������p�̉摜�z�u�ꏊ���Z�b�g����
	void SetSelectMapChipPlacePos();
	// �X�e�[�W���������o��
	void ExportStage();
	// �}�b�v��h��
	void PaintMapChip(int x, int y, int chipInde, Rect chipRectPos);
	// �}�b�v�`�b�v���ړ�������
	void ChangeMapChipSelect(int x, int y, Rect chipRectPos);
	// �}�b�v�`�b�v���ړ�
	void ChangingMapChip(int x, int y, Rect chipRectPos);
	// �}�b�v�`�b�v�̏�Ԃ���O�ɖ߂�
	void RevertBackMap();

	// �G�f�B�^�[�̃}�b�v�`�b�v��\��
	void EditorDraw();
	// �I������p�̃}�b�v�`�b�v��\��
	void SelectMapChipDraw();

	// �}�E�X�J�[�\�����}�b�v�`�b�v���ɂ��邩�ǂ���
	bool IsRectMouseOver(Rect chipRectPos);
	// �}�b�v�`�b�v���ŃN���b�N���ꂽ���ǂ���
	bool IsRectClick(Rect chipRectPos,ClickState state);
	// ���݂�x,y���X�e�[�W��̒[���ǂ���
	bool IsRectEdge(int x, int y);

public:
	StageEditor();
	//�`��
	void Draw();
	//�X�V
	void Update();
};