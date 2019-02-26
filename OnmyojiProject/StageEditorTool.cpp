#include "StageEditorTool.h"
#include "DxLib.h"
#include "Input.h"


StageEditorTool::StageEditorTool()
{
	// �摜�ǂݍ���
	LoadDivGraph("TestMapChip4.png", allDivision, divisionX, divisionY, selectMapChipGraphSize, selectMapChipGraphSize, chipGh);
	backGroundGh = LoadGraph("BackGround.png");

	SetEditorPlacePos();
	SetSelectMapChipPlacePos();
}

/////////////////////////////////////////////////////
//����			:�X�e�[�W�����i�[����z���x,y�̓Y��
//�߂�l		:�X�e�[�W��̒[�ɂ����镔����������true
//����			:x,y���X�e�[�W�̒[���ǂ���
/////////////////////////////////////////////////////
bool StageEditorTool::IsRectEdge(int x, int y)
{
	if (y == 0 || y >= mapNumY - 1 || x == 0 || x >= mapNumX - 1) return true;
	else return false;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:��ʏ�ɃG�f�B�^�[��u���ʒu���Z�b�g
/////////////////////////////////////////////////////
void StageEditorTool::SetEditorPlacePos()
{
	// �z���������
	mapStageData.clear();
	chipPosVec.clear();
	chipRectPosVec.clear();

	// �񎟌��z��ɓ���邽�߂Ɉꎞ�I�ɒl���i�[����z��
	vector<int> tempMapStageData;
	vector<ChipPosition> tempChipPos;
	vector<Rect> tempRectPos;

	for (int y = 0; y < mapNumY; ++y)
	{
		for (int x = 0; x < mapNumX; ++x)
		{
			// �}�b�v�`�b�v�̈ʒu���擾
			tempChipPos.push_back(GetChipPos(x, y));

			// �}�b�v�`�b�v�̉摜�T�C�Y���擾
			tempRectPos.push_back(GetChipRect(x, y));

			// �[��������ǁA����ȊO�͒ʂ��ꏊ�Ƃ��Ĕz�u����
			if (IsRectEdge(x, y)) tempMapStageData.push_back(1);
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
ChipPosition StageEditorTool::GetChipPos(int x, int y)
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
Rect StageEditorTool::GetChipRect(int x, int y)
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
void StageEditorTool::SetSelectMapChipPlacePos()
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
void StageEditorTool::ExportStage()
{

}

/////////////////////////////////////////////////////
//����			:Rect�\����
//�߂�l		:�摜�̏�Ƀ}�E�X���̂��Ă�����true
//����			:�摜�̏�Ƀ}�E�X���̂��Ă��邩�ǂ���
/////////////////////////////////////////////////////
bool StageEditorTool::IsRectMouseOver(Rect chipRectPos)
{
	if (Collision::Instance()->CheckRectAndPoint(chipRectPos, mousePosX, mousePosY)) return true;
	else return false;
}

/////////////////////////////////////////////////////
//����			:Rect�\���́AClickState�񋓑�
//�߂�l		:�摜���N���b�N����Ă�����true
//����			:�}�E�X���摜�̏�ɂ����ԂŁA�N���b�N����Ă��邩�ǂ���
/////////////////////////////////////////////////////
bool StageEditorTool::IsRectClick(Rect chipRectPos, ClickState state)
{
	if (IsRectMouseOver(chipRectPos))
	{
		switch (state)
		{
		case leftClick: 
			if (Input::Instance()->Button(MOUSE_INPUT_LEFT)) return true;
			else return false;

		case rightClick: 
			if (Input::Instance()->Button(MOUSE_INPUT_RIGHT)) return true;
			else return false;

		case anyClick: 
			if (Input::Instance()->Button(MOUSE_INPUT_LEFT) || Input::Instance()->Button(MOUSE_INPUT_RIGHT)) return true;
			else return false;

		default: 
			return false;
		}
	}

	return false;
}

int tempX, tempY;
int tempChipIndex;

/////////////////////////////////////////////////////
//����			:�X�e�[�W�f�[�^�̔z��̓Y����x,y �ύX�������}�b�v�`�b�v�̎�ށ@Rect�\����
//�߂�l		:�Ȃ�
//����			:�}�b�v�`�b�v�̕ύX����
/////////////////////////////////////////////////////
void StageEditorTool::PaintMapChip(int x, int y, int chipInde, Rect chipRectPos)
{
	if (IsRectClick(chipRectPos, leftClick) && isChipChanging == false)
	{
		if (tempX != x || tempY != y || tempChipIndex != chipInde)
		{
			DrawGraph(0, 500, chipGh[4], TRUE);
			mapStageData[y][x] = chipInde;
		}

		tempX = x;
		tempY = y;
		tempChipIndex = chipInde;
	}
}

/////////////////////////////////////////////////////
//����			:�G�f�B�^�[�`��
//�߂�l		:�Ȃ�
//����			:�}�b�v�`�b�v���z�u����Ă���G�f�B�^�[��`�悷��
/////////////////////////////////////////////////////
void StageEditorTool::EditorDraw()
{
	for (int y = 0; y < mapNumY; y++)
	{
		for (int x = 0; x < mapNumX; ++x)
		{
			// �摜��`��
			DrawRotaGraph(chipPosVec[y][x].drawPosX, chipPosVec[y][x].drawPosY, 0.25, 0.0, chipGh[mapStageData[y][x]], TRUE);

			// �X�e�[�W�G�f�B�^�[�̒[�͕ǌŒ�B
			// ����ȊO���N���b�N����Ă�����}�b�v�`�b�v�ϊ�����
			if (IsRectEdge(x, y) == false)
			{
				PaintMapChip(x, y, chipIndex, chipRectPosVec[y][x]);
				ChangeMapChipSelect(x, y, chipRectPosVec[y][x]);
				ChangingMapChip(x, y, chipRectPosVec[y][x]);
			}
		}
	}
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�I��p�}�b�v�`�b�v�̕`��
/////////////////////////////////////////////////////
void StageEditorTool::SelectMapChipDraw()
{
	for (int i = 0; i < selectChipNum; ++i)
	{
		// �I��p�̃}�b�v�`�b�v��\��
		DrawGraph(selectChipPosVec[i].drawPosX, selectChipPosVec[i].drawPosY, chipGh[i], TRUE);

		// �I��p�̃}�b�v�`�b�v���N���b�N����Ă�����
		if (IsRectClick(selectChipRectPosVec[i],leftClick))
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
//����			:�}�b�v�`�b�v��ύX����
/////////////////////////////////////////////////////
void StageEditorTool::ChangeMapChipSelect(int x, int y, Rect chipRectPos)
{
	// �G�f�B�^�[��̃}�b�v�`�b�v��ŉE�N���b�N������Ă��� �� ���݃}�b�v�������łȂ����
	if (IsRectClick(chipRectPos, rightClick) && isChipChanging == false)
	{
		// �}�b�v���������Ă��邩�ǂ����𔻒f����t���O
		isChipChanging = true;

		changinMapX = x;
		changinMapY = y;

		changinChipIndex = mapStageData[y][x];
	}

	// �I�𒆂̃`�b�v�𕪂���₷�������ԂőI��\��
	if (isChipChanging && changinMapX == x && changinMapY == y)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

		DrawBox(chipRectPosVec[y][x].left, chipRectPosVec[y][x].top, chipRectPosVec[y][x].right, chipRectPosVec[y][x].bottom, GetColor(255, 0, 0), TRUE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}


}

void StageEditorTool::ChangingMapChip(int x, int y, Rect chipRectPos)
{
	if (isChipChanging)
	{
		if (IsRectClick(chipRectPos, leftClick))
		{
			mapStageData[y][x] = changinChipIndex;
			mapStageData[changinMapY][changinMapX] = 0;

			isChipChanging = false;
			changinMapX = 0;
			changinMapY = 0;
			changinChipIndex = 0;
		}
	}
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:��O�ɖ߂�
/////////////////////////////////////////////////////
void StageEditorTool::RevertBackMap()
{

}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�`��
/////////////////////////////////////////////////////
void StageEditorTool::Draw()
{
	DrawGraph(0, 0, backGroundGh,FALSE);

	EditorDraw();
	SelectMapChipDraw();
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�V
/////////////////////////////////////////////////////
void StageEditorTool::Update()
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