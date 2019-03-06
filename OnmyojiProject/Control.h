#pragma once

#include <string>
#include <vector>
#include "GameScene.h"
#include "StageInpoter.h"
#include "ImageLoader.h"

using namespace std;


/*
///////////////////////////////////////////
SceneStage�񋓑�

�T�v�@�F�V�[���̏�Ԃ𔻕ʂ���
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

	unique_ptr<GameScene> gameScene = make_unique<GameScene>();

	// ���݂̃V�[��
	SceneState sceneState;

	//===============================
	// �֐�
	//===============================

public:
	Control();

	// �V�[���Έ�
	void SceneChange(SceneState scene);

	void Update();
};