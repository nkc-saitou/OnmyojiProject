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
GameControl�N���X

�T�v�@�F�V�[���Ǘ�
///////////////////////////////////////////
*/
class Control
{
	//===============================
	// �ϐ�
	//===============================

	unique_ptr<TitleScene> titleScene = make_unique<TitleScene>();
	unique_ptr<GameScene> gameScene = make_unique<GameScene>();

	// ���݂̃V�[��
	SceneState sceneState = SceneState::titleScene;
	// �O��t���[���̃V�[���L�^�p
	SceneState memoryState = SceneState::titleScene;

	//===============================
	// �֐�
	//===============================

	// �V�[���J�ڏ���
	void ChangeScene();

public:
	Control();


	void Update();

};