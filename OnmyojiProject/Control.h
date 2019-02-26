#pragma once

#include <string>
#include <vector>
#include "GameScene.h"
#include "StageInpoter.h"
#include "ImageLoader.h"

using namespace std;


/*
///////////////////////////////////////////
SceneStage列挙体

概要　：シーンの状態を判別する
///////////////////////////////////////////
*/
enum SceneState
{
	titleScene,
	selectScene,
	gameScene,
	resultScene,
	toolScene,
};

using namespace std;

/*
///////////////////////////////////////////
GameControlクラス

概要　：シーン管理
///////////////////////////////////////////
*/
class Control
{
	//===============================
	// 変数
	//===============================

	unique_ptr<GameScene> gameScene = make_unique<GameScene>(0);

	// 現在のシーン
	SceneState sceneState;

	//===============================
	// 関数
	//===============================

public:
	Control();

	// シーン偏移
	void SceneChange(SceneState scene);

	void Update();
};