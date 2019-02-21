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
	//スクリーンサイズ
	const int screenScaleX = 1920;
	const int screenScaleY = 1080;

	// イメージのサイズ
	const int mapChipGraphSize = 32;
	const int selectMapChipGraphSize = 128;

	// イメージ全体の分割数
	const int allDivision = 7;

	// 横の分割数
	const int divisionX = 7;

	// 縦の分割数
	const int divisionY = 1;

	// マップエディタ全体の配置地点
	const int mapEditorPosX = screenScaleX / 3;
	const int mapEditorPosY = screenScaleY / 3;

	// マップチップの画像配列の添字
	int chipIndex = 0;

	// マップチップのグラフィックハンドル
	int chipGh[7];

	// マウス位置の取得
	int mousePosX, mousePosY;

	// マップチップを縦横にそれぞれ配置する数
	double mapNumX = screenScaleX / 64;
	double mapNumY = screenScaleY / 64;

	// 各マスに何が置かれているかを記憶するデータ配列
	vector<vector<int>> mapStageData = vector<vector<int>>();

	// マップチップとして配置する画像サイズを上下左右で取得
	vector<vector<Rect>> chipRectPosVec = vector<vector<Rect>>();
	// マップチップとして配置する画像の位置情報を取得
	vector<vector<ChipPosition>> chipPosVec = vector<vector<ChipPosition>>();

	// マップチップを選択する用のオブジェクトの画像サイズを上下左右で取得
	vector<Rect> selectChipRectPosVec = vector<Rect>();
	// 選択する用の画像の位置情報を取得
	vector<ChipPosition> selectChipPosVec = vector<ChipPosition>();



	//===============================
	// 関数
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