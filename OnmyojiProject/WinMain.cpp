#include <memory>

#include "DxLib.h"
#include "Input.h"
#include "FpsFix.h"
#include "Control.h"
#include "SettingProvider.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 1920x1080
	const int screenSizeX = SettingProvider::Instance()->screenSizeX;
	const int screenSizeY = SettingProvider::Instance()->screenSizeY;

	// �g�p����F�̃r�b�g��
	const int colorBitDepth = 32;

	//�E�B���h�E�\��
	ChangeWindowMode(true);
	SetMainWindowText("�A�z�t");
	SetGraphMode(screenSizeX, screenSizeY, colorBitDepth);//��ʃT�C�Y�w��

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1) return -1;	//�G���[���N������I��

	// �S�Ă̓������Ǘ�����N���X
	std::unique_ptr<Control> control(new Control);

	//�_�u���o�b�t�@�����O
	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);


	while (ProcessMessage() == 0)
	{
		control->Update();

		FpsFix::Instance()->Updata();     // FPS�Œ�
		Input::Instance()->InputMemory(); // Input���X�V

		ScreenFlip();	//����ʂ�\��ʂɃR�s�[
		ClearDrawScreen();	//����ʏ���
	}

	DxLib_End();

	return 0;
}