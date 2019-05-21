#pragma once

/*
///////////////////////////////////////////
SceneStage

概要　：シーンの状態を判別する
///////////////////////////////////////////
*/
enum class SceneState
{
	titleScene = 0,
	selectScene,
	gameScene,
	resultScene,
	toolScene,
};