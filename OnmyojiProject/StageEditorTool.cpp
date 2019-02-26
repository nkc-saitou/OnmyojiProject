#include "StageEditorTool.h"
#include "DxLib.h"
#include "Input.h"


StageEditorTool::StageEditorTool()
{
	// 画像読み込み
	LoadDivGraph("TestMapChip4.png", allDivision, divisionX, divisionY, selectMapChipGraphSize, selectMapChipGraphSize, chipGh);
	backGroundGh = LoadGraph("BackGround.png");

	SetEditorPlacePos();
	SetSelectMapChipPlacePos();
}

/////////////////////////////////////////////////////
//引数			:ステージ情報を格納する配列のx,yの添字
//戻り値		:ステージ上の端にあたる部分だったらtrue
//動作			:x,yがステージの端かどうか
/////////////////////////////////////////////////////
bool StageEditorTool::IsRectEdge(int x, int y)
{
	if (y == 0 || y >= mapNumY - 1 || x == 0 || x >= mapNumX - 1) return true;
	else return false;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:画面上にエディターを置く位置をセット
/////////////////////////////////////////////////////
void StageEditorTool::SetEditorPlacePos()
{
	// 配列を初期化
	mapStageData.clear();
	chipPosVec.clear();
	chipRectPosVec.clear();

	// 二次元配列に入れるために一時的に値を格納する配列
	vector<int> tempMapStageData;
	vector<ChipPosition> tempChipPos;
	vector<Rect> tempRectPos;

	for (int y = 0; y < mapNumY; ++y)
	{
		for (int x = 0; x < mapNumX; ++x)
		{
			// マップチップの位置を取得
			tempChipPos.push_back(GetChipPos(x, y));

			// マップチップの画像サイズを取得
			tempRectPos.push_back(GetChipRect(x, y));

			// 端だったら壁、それ以外は通れる場所として配置する
			if (IsRectEdge(x, y)) tempMapStageData.push_back(1);
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
ChipPosition StageEditorTool::GetChipPos(int x, int y)
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
//引数			:なし
//戻り値		:なし
//動作			:マップチップ選択用チップの配置場所をセット
/////////////////////////////////////////////////////
void StageEditorTool::SetSelectMapChipPlacePos()
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
void StageEditorTool::ExportStage()
{

}

/////////////////////////////////////////////////////
//引数			:Rect構造体
//戻り値		:画像の上にマウスがのっていたらtrue
//動作			:画像の上にマウスがのっているかどうか
/////////////////////////////////////////////////////
bool StageEditorTool::IsRectMouseOver(Rect chipRectPos)
{
	if (Collision::Instance()->CheckRectAndPoint(chipRectPos, mousePosX, mousePosY)) return true;
	else return false;
}

/////////////////////////////////////////////////////
//引数			:Rect構造体、ClickState列挙体
//戻り値		:画像がクリックされていたらtrue
//動作			:マウスが画像の上にある状態で、クリックされているかどうか
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
//引数			:ステージデータの配列の添え字x,y 変更したいマップチップの種類　Rect構造体
//戻り値		:なし
//動作			:マップチップの変更処理
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
//引数			:エディター描画
//戻り値		:なし
//動作			:マップチップが配置されているエディターを描画する
/////////////////////////////////////////////////////
void StageEditorTool::EditorDraw()
{
	for (int y = 0; y < mapNumY; y++)
	{
		for (int x = 0; x < mapNumX; ++x)
		{
			// 画像を描画
			DrawRotaGraph(chipPosVec[y][x].drawPosX, chipPosVec[y][x].drawPosY, 0.25, 0.0, chipGh[mapStageData[y][x]], TRUE);

			// ステージエディターの端は壁固定。
			// それ以外がクリックされていたらマップチップ変換処理
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
//引数			:なし
//戻り値		:なし
//動作			:選択用マップチップの描画
/////////////////////////////////////////////////////
void StageEditorTool::SelectMapChipDraw()
{
	for (int i = 0; i < selectChipNum; ++i)
	{
		// 選択用のマップチップを表示
		DrawGraph(selectChipPosVec[i].drawPosX, selectChipPosVec[i].drawPosY, chipGh[i], TRUE);

		// 選択用のマップチップがクリックされていたら
		if (IsRectClick(selectChipRectPosVec[i],leftClick))
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
//動作			:マップチップを変更する
/////////////////////////////////////////////////////
void StageEditorTool::ChangeMapChipSelect(int x, int y, Rect chipRectPos)
{
	// エディター上のマップチップ上で右クリックをされている ＆ 現在マップ交換中でなければ
	if (IsRectClick(chipRectPos, rightClick) && isChipChanging == false)
	{
		// マップを交換しているかどうかを判断するフラグ
		isChipChanging = true;

		changinMapX = x;
		changinMapY = y;

		changinChipIndex = mapStageData[y][x];
	}

	// 選択中のチップを分かりやすく薄い赤で選択表示
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
//引数			:なし
//戻り値		:なし
//動作			:一つ前に戻す
/////////////////////////////////////////////////////
void StageEditorTool::RevertBackMap()
{

}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:描画
/////////////////////////////////////////////////////
void StageEditorTool::Draw()
{
	DrawGraph(0, 0, backGroundGh,FALSE);

	EditorDraw();
	SelectMapChipDraw();
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:更新
/////////////////////////////////////////////////////
void StageEditorTool::Update()
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