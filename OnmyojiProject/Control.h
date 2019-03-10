#pragma once

#include <string>
#include <vector>
#include <functional>

#include "GameScene.h"
#include "TitleScene.h"
#include "StageInpoter.h"
#include "ImageLoader.h"
#include "E_SceneState.h"

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

	unique_ptr<TitleScene> titleScene = make_unique<TitleScene>();
	unique_ptr<GameScene> gameScene = make_unique<GameScene>();

	// 現在のシーン
	SceneState sceneState = SceneState::titleScene;
	// 前回フレームのシーン記録用
	SceneState memoryState = SceneState::titleScene;

	//===============================
	// 関数
	//===============================

	// シーン遷移処理
	void ChangeScene();

public:
	Control();


	void Update();

};