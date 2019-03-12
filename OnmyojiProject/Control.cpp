#include "Control.h"
#include "DxLib.h"
#include "AudioManager.h"
#include "Input.h"

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�摜�̓ǂݍ���
/////////////////////////////////////////////////////
Control::Control()
{
	ImageLoader::Instance()->ImageDiv();
	AudioManager::Instance()->LoadSound();

	AudioManager::Instance()->PlayBGM(AudioManager::Instance()->GetBGM_TitleSH());

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
		if (isSceneChange(memoryState, sceneState))
		{
			AudioManager::Instance()->PlayBGM(AudioManager::Instance()->GetBGM_TitleSH());
		}

		titleScene->Uptate();
		break;

	case SceneState::selectScene:
		break;

	case SceneState::gameScene:
		if (isSceneChange(memoryState, sceneState))
		{
			AudioManager::Instance()->PlayBGM(AudioManager::Instance()->GetBGM_GameSh());
			gameScene->SetStage(0);
		}

		gameScene->Update();
		break;

	case SceneState::resultScene:
		if (isSceneChange(memoryState, sceneState))
		{
			AudioManager::Instance()->PlayBGM(AudioManager::Instance()->GetBGM_ResultSh());
			resultScene->Init();
		}
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