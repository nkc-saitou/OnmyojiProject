#include "StageEditor.h"
#include "DxLib.h"
#include "Input.h"


StageEditor::StageEditor()
{
	// 画像読み込み
	LoadDivGraph("TestMapChip3.png", allDivision, divisionX, divisionY, selectMapChipGraphSize, selectMapChipGraphSize, chipGh);

	SetMapChipPlacePos();
	SetSelectMapChipPlacePos();
}

bool StageEditor::IsRectEdge(int x, int y)
{
	if (y == 0 || y == mapNumY - 1 || x == 0 || x == mapNumX - 1) return true;
	else return false;
}


void StageEditor::SetMapChipPlacePos()
{
	mapStageData.clear();
	chipPosVec.clear();
	chipRectPosVec.clear();

	vector<int> tempMapStageData = vector<int>();
	vector<ChipPosition> tempChipPos = vector<ChipPosition>();
	vector<Rect> tempRectPos = vector<Rect>();

	// 配列の中身を初期化
	for (int i = 0; i < mapNumY; ++i)
	{
		for (int j = 0; j < mapNumX; ++j)
		{
			tempChipPos.push_back(GetChipCenterPos(j, i));

			tempRectPos.push_back(GetChipRectPos(j, i));

			if (IsRectEdge(j, i)) tempMapStageData.push_back(1);
			else tempMapStageData.push_back(0);
		}

		mapStageData.push_back(tempMapStageData);
		chipPosVec.push_back(tempChipPos);
		chipRectPosVec.push_back(tempRectPos);

		tempMapStageData.clear();
		tempChipPos.clear();
		tempRectPos.clear();
	}
}

ChipPosition StageEditor::GetChipCenterPos(int x, int y)
{
	ChipPosition chipPos;

	chipPos.drawPosX = mapEditorPosX + (mapChipGraphSize * x);
	chipPos.drawPosY = mapEditorPosY + (mapChipGraphSize * y);

	return chipPos;
}

Rect StageEditor::GetChipRectPos(int x, int y)
{
	Rect chipRectPos;

	chipRectPos.top = GetChipCenterPos(x, y).drawPosY - (mapChipGraphSize / 2);
	chipRectPos.left = GetChipCenterPos(x, y).drawPosX - (mapChipGraphSize / 2);
	chipRectPos.bottom = chipRectPos.top + mapChipGraphSize;
	chipRectPos.right = chipRectPos.left + mapChipGraphSize;

	return chipRectPos;
}

void StageEditor::SetSelectMapChipPlacePos()
{
	selectChipPosVec.clear();
	selectChipRectPosVec.clear();

	ChipPosition selectChipPos;

	Rect selectChipRectPos;

	for (int i = 0; i < allDivision + 1; ++i)
	{
		selectChipPos.drawPosY = (selectMapChipGraphSize / 2) + selectMapChipGraphSize * i;
		selectChipPos.drawPosX = selectMapChipGraphSize * 2;
		selectChipPosVec.push_back(selectChipPos);

		selectChipRectPos.top = selectChipPos.drawPosY;
		selectChipRectPos.left = selectChipPos.drawPosX;
		selectChipRectPos.bottom = selectChipRectPos.top + selectMapChipGraphSize;
		selectChipRectPos.right = selectChipRectPos.left + selectMapChipGraphSize;

		selectChipRectPosVec.push_back(selectChipRectPos);
	}
}


void StageEditor::ExportStage()
{

}

bool StageEditor::IsRectMouseOver(Rect chipRectPos)
{
	if (Collision::Instance()->CheckRectAndPoint(chipRectPos, mousePosX, mousePosY)) return true;
	else return false;
}

bool StageEditor::IsRectClick(Rect chipRectPos)
{
	if (IsRectMouseOver(chipRectPos) && Input::Instance()->Button(MOUSE_INPUT_LEFT)) return true;
	else return false;
}


void StageEditor::ChangeMapChip(int x, int y, int chipInde, Rect chipRectPos)
{
	if(IsRectClick(chipRectPos)) mapStageData[x][y] = chipInde;
}

void StageEditor::MapChipDraw()
{
	for (int i = 0; i < mapNumY; i++)
	{
		for (int j = 0; j < mapNumX; ++j)
		{
			DrawRotaGraph(chipPosVec[i][j].drawPosX, chipPosVec[i][j].drawPosY, 0.25, 0.0, chipGh[mapStageData[i][j]], TRUE);

			if (IsRectEdge(j, i) == false) ChangeMapChip(i, j, chipIndex, chipRectPosVec[i][j]);

		}
	}
}

void StageEditor::SelectMapChipDraw()
{
	for (int i = 0; i < allDivision + 1; ++i)
	{
		DrawGraph(selectChipPosVec[i].drawPosX, selectChipPosVec[i].drawPosY, chipGh[i], TRUE);

		if (IsRectClick(selectChipRectPosVec[i]))
		{
			chipIndex = i;

			//ボタンを押した際の演出
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
			DrawBox(selectChipRectPosVec[i].left, selectChipRectPosVec[i].top, selectChipRectPosVec[i].right, selectChipRectPosVec[i].bottom,GetColor(255, 255, 255), TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}

void StageEditor::Draw()
{
	MapChipDraw();
	SelectMapChipDraw();
}

void StageEditor::Update()
{
	// マウスの位置を取得
	GetMousePoint(&mousePosX, &mousePosY);

	if (Input::Instance()->Button(MOUSE_INPUT_RIGHT))
	{
		SetMapChipPlacePos();
	}

	Draw();
}