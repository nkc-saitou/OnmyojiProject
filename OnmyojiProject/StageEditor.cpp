#include "StageEditor.h"
#include "DxLib.h"
#include "Input.h"


StageEditor::StageEditor()
{
	// 画像読み込み
	LoadDivGraph("TestMapChip4.png", allDivision, divisionX, divisionY, selectMapChipGraphSize, selectMapChipGraphSize, chipGh);

	SetEditorPlacePos();
	SetSelectMapChipPlacePos();
}

/////////////////////////////////////////////////////
//引数			:ステージ情報を格納する配列のx,yの添字
//戻り値		:ステージ上の端にあたる部分だったらtrue
//動作			:x,yがステージの端かどうか
/////////////////////////////////////////////////////
bool StageEditor::IsRectEdge(int x, int y)
{
	if (y == 0 || y >= mapNumY - 1 || x == 0 || x >= mapNumX - 1) return true;
	else return false;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:画面上にエディターを置く位置をセット
/////////////////////////////////////////////////////
void StageEditor::SetEditorPlacePos()
{
	// 配列を初期化
	mapStageData.clear();
	chipPosVec.clear();
	chipRectPosVec.clear();

	// 二次元配列に入れるために一時的に値を格納する配列
	vector<int> tempMapStageData;
	vector<ChipPosition> tempChipPos;
	vector<Rect> tempRectPos;

	for (int i = 0; i < mapNumY; ++i)
	{
		for (int j = 0; j < mapNumX; ++j)
		{
			// マップチップの位置を取得
			tempChipPos.push_back(GetChipPos(j, i));

			// マップチップの画像サイズを取得
			tempRectPos.push_back(GetChipRect(j, i));

			// 端だったら壁、それ以外は通れる場所として配置する
			if (IsRectEdge(j, i)) tempMapStageData.push_back(1);
			else tempMapStageData.push_back(0);
		}

		// 一時的に保存した一次元配列を二次元配列に入れる
		mapStageData.push_back(tempMapStageData);
		chipPosVec.push_back(tempChipPos);
		chipRectPosVec.push_back(tempRectPos);

		// 配列を初期化
		tempMapStageData.clear();
		tempChipPos.clear();
		tempRectPos.clear();
	}
}

/////////////////////////////////////////////////////
//引数			:マップチップ一つ一つのx,y配列添字
//戻り値		:位置情報が格納されたChipOosition構造体
//動作			:マップチップの位置情報を取得
/////////////////////////////////////////////////////
ChipPosition StageEditor::GetChipPos(int x, int y)
{
	ChipPosition chipPos;

	chipPos.drawPosX = mapEditorPosX + (mapChipGraphSize * x);
	chipPos.drawPosY = mapEditorPosY + (mapChipGraphSize * y);

	return chipPos;
}

/////////////////////////////////////////////////////
//引数			:マップチップ一つ一つのx,y配列添字
//戻り値		:位置情報が格納されたRect構造体
//動作			:マップチップ画像の上下左右の座標位置を取得
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
//引数			:なし
//戻り値		:なし
//動作			:マップチップ選択用チップの配置場所をセット
/////////////////////////////////////////////////////
void StageEditor::SetSelectMapChipPlacePos()
{
	// 配列を初期化
	selectChipPosVec.clear();
	selectChipRectPosVec.clear();

	ChipPosition selectChipPos;
	Rect selectChipRectPos;

	for (int i = 0; i < selectChipNum; ++i)
	{
		// 描画位置をセット
		selectChipPos.drawPosY = (selectMapChipGraphSize / 2) + selectMapChipGraphSize * i;
		selectChipPos.drawPosX = selectMapChipGraphSize * 2;

		//配列に格納
		selectChipPosVec.push_back(selectChipPos);


		// 画像の上下左右の座標情報をセット
		selectChipRectPos.top = selectChipPos.drawPosY;
		selectChipRectPos.left = selectChipPos.drawPosX;
		selectChipRectPos.bottom = selectChipRectPos.top + selectMapChipGraphSize;
		selectChipRectPos.right = selectChipRectPos.left + selectMapChipGraphSize;

		// 配列に格納
		selectChipRectPosVec.push_back(selectChipRectPos);
	}
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:ステージを書き出し
/////////////////////////////////////////////////////
void StageEditor::ExportStage()
{

}

/////////////////////////////////////////////////////
//引数			:Rect構造体
//戻り値		:画像の上にマウスがのっていたらtrue
//動作			:画像の上にマウスがのっているかどうか
/////////////////////////////////////////////////////
bool StageEditor::IsRectMouseOver(Rect chipRectPos)
{
	if (Collision::Instance()->CheckRectAndPoint(chipRectPos, mousePosX, mousePosY)) return true;
	else return false;
}

/////////////////////////////////////////////////////
//引数			:Rect構造体
//戻り値		:画像がクリックされていたらtrue
//動作			:マウスが画像の上にある状態で、クリックされているかどうか
/////////////////////////////////////////////////////
bool StageEditor::IsRectClick(Rect chipRectPos)
{
	if (IsRectMouseOver(chipRectPos) && Input::Instance()->Button(MOUSE_INPUT_LEFT)) return true;
	else return false;
}

/////////////////////////////////////////////////////
//引数			:ステージデータの配列の添え字x,y マップチップの種類　Rect構造体
//戻り値		:なし
//動作			:マップチップの変更処理
/////////////////////////////////////////////////////
void StageEditor::ChangeMapChip(int x, int y, int chipInde, Rect chipRectPos)
{


	if(IsRectClick(chipRectPos)) mapStageData[x][y] = chipInde;
}

/////////////////////////////////////////////////////
//引数			:エディター描画
//戻り値		:なし
//動作			:マップチップが配置されているエディターを描画する
/////////////////////////////////////////////////////
void StageEditor::EditorDraw()
{
	for (int i = 0; i < mapNumY; i++)
	{
		for (int j = 0; j < mapNumX; ++j)
		{
			// 画像を描画
			DrawRotaGraph(chipPosVec[i][j].drawPosX, chipPosVec[i][j].drawPosY, 0.25, 0.0, chipGh[mapStageData[i][j]], TRUE);

			// ステージエディターの端は壁固定。
			// それ以外がクリックされていたらマップチップ変換処理
			if (IsRectEdge(j, i) == false) ChangeMapChip(i, j, chipIndex, chipRectPosVec[i][j]);

		}
	}
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:選択用マップチップの描画
/////////////////////////////////////////////////////
void StageEditor::SelectMapChipDraw()
{
	for (int i = 0; i < selectChipNum; ++i)
	{
		// 選択用のマップチップを表示
		DrawGraph(selectChipPosVec[i].drawPosX, selectChipPosVec[i].drawPosY, chipGh[i], TRUE);

		// 選択用のマップチップがクリックされていたら
		if (IsRectClick(selectChipRectPosVec[i]))
		{
			// 設置するマップチップを変更する
			chipIndex = i;

			//ボタンを押した際、少し薄いボックスを出して押した感を出す演出
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

			DrawBox(selectChipRectPosVec[i].left, selectChipRectPosVec[i].top, selectChipRectPosVec[i].right, 
				selectChipRectPosVec[i].bottom,GetColor(255, 255, 255), TRUE);

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:描画
/////////////////////////////////////////////////////
void StageEditor::Draw()
{
	EditorDraw();
	SelectMapChipDraw();
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:更新
/////////////////////////////////////////////////////
void StageEditor::Update()
{
	// マウスの位置を取得
	GetMousePoint(&mousePosX, &mousePosY);

	//// 右クリックするとエディターリセット
	//if (Input::Instance()->Button(MOUSE_INPUT_RIGHT))
	//{
	//	SetEditorPlacePos();
	//}

	// 描画
	Draw();
}