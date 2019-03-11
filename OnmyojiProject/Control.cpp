#include "Control.h"
#include "DxLib.h"

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�摜�̓ǂݍ���
/////////////////////////////////////////////////////
Control::Control()
{
	ImageLoader::Instance()->ImageDiv();

}


/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�摜�̓ǂݍ���
/////////////////////////////////////////////////////
void Control::ChangeScene()
{
	sceneState = SettingProvider::Instance()->GetSceneState();

	// �V�[���J�ڂ������ǂ���
	auto isSceneChange = [](SceneState memoryState, SceneState sceneState)
	{
		return (memoryState != sceneState) ? true : false;
	};

	switch (sceneState)
	{
	case SceneState::titleScene:
		titleScene->Uptate();
		break;

	case SceneState::selectScene:
		break;

	case SceneState::gameScene:
		if (isSceneChange(memoryState, sceneState)) gameScene->SetStage(0);
		gameScene->Update();
		break;

	case SceneState::resultScene:
		if (isSceneChange(memoryState, sceneState)) resultScene->Init();
		resultScene->Update();
		break;
	}

	// �X�V
	memoryState = sceneState;
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�X�V
/////////////////////////////////////////////////////
void Control::Update()
{
	ChangeScene();
}