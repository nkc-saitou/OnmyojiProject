#include "StageEditor.h"
#include "DxLib.h"
#include "Input.h"


StageEditor::StageEditor()
{
	// �摜�ǂݍ���
	LoadDivGraph("TestMapChip4.png", allDivision, divisionX, divisionY, selectMapChipGraphSize, selectMapChipGraphSize, chipGh);

	SetEditorPlacePos();
	SetSelectMapChipPlacePos();
}

/////////////////////////////////////////////////////
//����			:�X�e�[�W�����i�[����z���x,y�̓Y��
//�߂�l		:�X�e�[�W��̒[�ɂ����镔����������true
//����			:x,y���X�e�[�W�̒[���ǂ���
/////////////////////////////////////////////////////
bool StageEditor::IsRectEdge(int x, int y)
{
	if (y == 0 || y >= mapNumY - 1 || x == 0 || x >= mapNumX - 1) return true;
	else return false;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:��ʏ�ɃG�f�B�^�[��u���ʒu���Z�b�g
/////////////////////////////////////////////////////
void StageEditor::SetEditorPlacePos()
{
	// �z���������
	mapStageData.clear();
	chipPosVec.clear();
	chipRectPosVec.clear();

	// �񎟌��z��ɓ���邽�߂Ɉꎞ�I�ɒl���i�[����z��
	vector<int> tempMapStageData;
	vector<ChipPosition> tempChipPos;
	vector<Rect> tempRectPos;

	for (int i = 0; i < mapNumY; ++i)
	{
		for (int j = 0; j < mapNumX; ++j)
		{
			// �}�b�v�`�b�v�̈ʒu���擾
			tempChipPos.push_back(GetChipPos(j, i));

			// �}�b�v�`�b�v�̉摜�T�C�Y���擾
			tempRectPos.push_back(GetChipRect(j, i));

			// �[��������ǁA����ȊO�͒ʂ��ꏊ�Ƃ��Ĕz�u����
			if (IsRectEdge(j, i)) tempMapStageData.push_back(1);
			else tempMapStageData.push_back(0);
		}

		// �ꎞ�I�ɕۑ������ꎟ���z���񎟌��z��ɓ����
		mapStageData.push_back(tempMapStageData);
		chipPosVec.push_back(tempChipPos);
		chipRectPosVec.push_back(tempRectPos);

		// �z���������
		tempMapStageData.clear();
		tempChipPos.clear();
		tempRectPos.clear();
	}
}

/////////////////////////////////////////////////////
//����			:�}�b�v�`�b�v����x,y�z��Y��
//�߂�l		:�ʒu��񂪊i�[���ꂽChipOosition�\����
//����			:�}�b�v�`�b�v�̈ʒu�����擾
/////////////////////////////////////////////////////
ChipPosition StageEditor::GetChipPos(int x, int y)
{
	ChipPosition chipPos;

	chipPos.drawPosX = mapEditorPosX + (mapChipGraphSize * x);
	chipPos.drawPosY = mapEditorPosY + (mapChipGraphSize * y);

	return chipPos;
}

/////////////////////////////////////////////////////
//����			:�}�b�v�`�b�v����x,y�z��Y��
//�߂�l		:�ʒu��񂪊i�[���ꂽRect�\����
//����			:�}�b�v�`�b�v�摜�̏㉺���E�̍��W�ʒu���擾
/////////////////////////////////////////////////////
Rect StageEditor::GetChipRect(int x, int y)
{
	Rect chipRectPos;

	chipRectPos.top = GetChipPos(x, y).drawPosY - (mapChipGraphSize / 2);
	chipRectPos.left = GetChipPos(x, y).drawPosX - (mapChipGraphSize / 2);
	chipRectPos.bottom = chipRectPos.top + mapChipGraphSize;
	chipRectPos.right = chipRectPos.left + mapChipGraphSize;

	return chipRectPos;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�}�b�v�`�b�v�I��p�`�b�v�̔z�u�ꏊ���Z�b�g
/////////////////////////////////////////////////////
void StageEditor::SetSelectMapChipPlacePos()
{
	// �z���������
	selectChipPosVec.clear();
	selectChipRectPosVec.clear();

	ChipPosition selectChipPos;
	Rect selectChipRectPos;

	for (int i = 0; i < selectChipNum; ++i)
	{
		// �`��ʒu���Z�b�g
		selectChipPos.drawPosY = (selectMapChipGraphSize / 2) + selectMapChipGraphSize * i;
		selectChipPos.drawPosX = selectMapChipGraphSize * 2;

		//�z��Ɋi�[
		selectChipPosVec.push_back(selectChipPos);


		// �摜�̏㉺���E�̍��W�����Z�b�g
		selectChipRectPos.top = selectChipPos.drawPosY;
		selectChipRectPos.left = selectChipPos.drawPosX;
		selectChipRectPos.bottom = selectChipRectPos.top + selectMapChipGraphSize;
		selectChipRectPos.right = selectChipRectPos.left + selectMapChipGraphSize;

		// �z��Ɋi�[
		selectChipRectPosVec.push_back(selectChipRectPos);
	}
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�e�[�W�������o��
/////////////////////////////////////////////////////
void StageEditor::ExportStage()
{

}

/////////////////////////////////////////////////////
//����			:Rect�\����
//�߂�l		:�摜�̏�Ƀ}�E�X���̂��Ă�����true
//����			:�摜�̏�Ƀ}�E�X���̂��Ă��邩�ǂ���
/////////////////////////////////////////////////////
bool StageEditor::IsRectMouseOver(Rect chipRectPos)
{
	if (Collision::Instance()->CheckRectAndPoint(chipRectPos, mousePosX, mousePosY)) return true;
	else return false;
}

/////////////////////////////////////////////////////
//����			:Rect�\����
//�߂�l		:�摜���N���b�N����Ă�����true
//����			:�}�E�X���摜�̏�ɂ����ԂŁA�N���b�N����Ă��邩�ǂ���
/////////////////////////////////////////////////////
bool StageEditor::IsRectClick(Rect chipRectPos)
{
	if (IsRectMouseOver(chipRectPos) && Input::Instance()->Button(MOUSE_INPUT_LEFT)) return true;
	else return false;
}

/////////////////////////////////////////////////////
//����			:�X�e�[�W�f�[�^�̔z��̓Y����x,y �}�b�v�`�b�v�̎�ށ@Rect�\����
//�߂�l		:�Ȃ�
//����			:�}�b�v�`�b�v�̕ύX����
/////////////////////////////////////////////////////
void StageEditor::ChangeMapChip(int x, int y, int chipInde, Rect chipRectPos)
{


	if(IsRectClick(chipRectPos)) mapStageData[x][y] = chipInde;
}

/////////////////////////////////////////////////////
//����			:�G�f�B�^�[�`��
//�߂�l		:�Ȃ�
//����			:�}�b�v�`�b�v���z�u����Ă���G�f�B�^�[��`�悷��
/////////////////////////////////////////////////////
void StageEditor::EditorDraw()
{
	for (int i = 0; i < mapNumY; i++)
	{
		for (int j = 0; j < mapNumX; ++j)
		{
			// �摜��`��
			DrawRotaGraph(chipPosVec[i][j].drawPosX, chipPosVec[i][j].drawPosY, 0.25, 0.0, chipGh[mapStageData[i][j]], TRUE);

			// �X�e�[�W�G�f�B�^�[�̒[�͕ǌŒ�B
			// ����ȊO���N���b�N����Ă�����}�b�v�`�b�v�ϊ�����
			if (IsRectEdge(j, i) == false) ChangeMapChip(i, j, chipIndex, chipRectPosVec[i][j]);

		}
	}
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�I��p�}�b�v�`�b�v�̕`��
/////////////////////////////////////////////////////
void StageEditor::SelectMapChipDraw()
{
	for (int i = 0; i < selectChipNum; ++i)
	{
		// �I��p�̃}�b�v�`�b�v��\��
		DrawGraph(selectChipPosVec[i].drawPosX, selectChipPosVec[i].drawPosY, chipGh[i], TRUE);

		// �I��p�̃}�b�v�`�b�v���N���b�N����Ă�����
		if (IsRectClick(selectChipRectPosVec[i]))
		{
			// �ݒu����}�b�v�`�b�v��ύX����
			chipIndex = i;

			//�{�^�����������ہA���������{�b�N�X���o���ĉ����������o�����o
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

			DrawBox(selectChipRectPosVec[i].left, selectChipRectPosVec[i].top, selectChipRectPosVec[i].right, 
				selectChipRectPosVec[i].bottom,GetColor(255, 255, 255), TRUE);

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�`��
/////////////////////////////////////////////////////
void StageEditor::Draw()
{
	EditorDraw();
	SelectMapChipDraw();
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�V
/////////////////////////////////////////////////////
void StageEditor::Update()
{
	// �}�E�X�̈ʒu���擾
	GetMousePoint(&mousePosX, &mousePosY);

	//// �E�N���b�N����ƃG�f�B�^�[���Z�b�g
	//if (Input::Instance()->Button(MOUSE_INPUT_RIGHT))
	//{
	//	SetEditorPlacePos();
	//}

	// �`��
	Draw();
}