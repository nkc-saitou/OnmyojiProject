#pragma once

#include "RectShape.h"
#include "Collision.h"
#include <memory>
#include <vector>


/*
///////////////////////////////////////////
ChipPosition

概要　：チップ一つの座標情報を格納
///////////////////////////////////////////
*/
struct ChipPosition
{
	int drawPosX;
	int drawPosY;
};

/*
///////////////////////////////////////////
StageEditorクラス

概要　：ステージエディター
///////////////////////////////////////////
*/
using namespace std;

class StageEditor
{
	//スクリーンサイズ
	const int screenScaleX = 1920;
	const int screenScaleY = 1080;

	// イメージのサイズ
	const int mapChipGraphSize = 32;
	const int selectMapChipGraphSize = 128;

	// イメージ全体の分割数
	const int allDivision = 11;

	// 横の分割数
	const int divisionX = 6;

	// 縦の分割数
	const int divisionY = 2;

	// マップチップを縦横それぞれ配置する数
	const int mapNumX = 30;
	const int mapNumY = 16;

	// 選択用のマップチップを配置する数
	const int selectChipNum = 5;

	// マップエディタ全体の配置地点
	const int mapEditorPosX = screenScaleX / 3;
	const int mapEditorPosY = screenScaleY / 3;

	// マップチップの画像配列の添字
	int chipIndex = 0;

	// マップチップのグラフィックハンドル
	int chipGh[11];

	// マウス位置の取得
	int mousePosX, mousePosY;

	// 各マスに何が置かれているかを記憶するデータ配列
	vector<vector<int>> mapStageData;

	// マップチップとして配置する画像サイズを上下左右で取得
	vector<vector<Rect>> chipRectPosVec;
	// マップチップとして配置する画像の位置情報を取得
	vector<vector<ChipPosition>> chipPosVec ;

	// マップチップを選択する用のオブジェクトの画像サイズを上下左右で取得
	vector<Rect> selectChipRectPosVec;
	// 選択する用の画像の位置情報を取得
	vector<ChipPosition> selectChipPosVec;


	//===============================
	// 関数
	//===============================

	// マップチップの上下左右の座標情報を取得
	Rect GetChipRect(int x, int y);
	// マップチップの位置情報を取得
	ChipPosition GetChipPos(int x, int y);

	// エディターの配置位置をセットする
	void SetEditorPlacePos();
	// マップチップ選択する用の画像配置場所をセットする
	void SetSelectMapChipPlacePos();
	// ステージ情報を書き出し
	void ExportStage();
	// マップチップを入れ替える処理
	void ChangeMapChip(int x, int y, int chipInde, Rect chipRectPos);
	// エディターのマップチップを表示
	void EditorDraw();
	// 選択する用のマップチップを表示
	void SelectMapChipDraw();

	// マウスカーソルがマップチップ内にあるかどうか
	bool IsRectMouseOver(Rect chipRectPos);
	// マップチップ内でクリックされたかどうか
	bool IsRectClick(Rect chipRectPos);
	// 現在のx,yがステージ上の端かどうか
	bool IsRectEdge(int x, int y);

public:
	StageEditor();
	//描画
	void Draw();
	//更新
	void Update();
};