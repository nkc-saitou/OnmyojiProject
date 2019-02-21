#include <memory>

#include "DxLib.h"
#include "Input.h"
#include "Player.h"
#include "Collision.h"
#include "StageEditor.h"

#include <vector>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 1920x1080
	const int screenSizeX = 1920;
	const int screenSizeY = 1080;

	//�E�B���h�E�\��
	ChangeWindowMode(true);
	SetMainWindowText("�A�z�t");
	SetGraphMode(screenSizeX, screenSizeY, 32);//��ʃT�C�Y�w��

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1) return -1;	//�G���[���N������I��

	//�_�u���o�b�t�@�����O
	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);


	//========Test==========

	Rect testPos;

	testPos.left = 300;
	testPos.top = 300;
	testPos.right = 500;
	testPos.bottom = 500;

	Circle circleTestPos;

	circleTestPos.x = 700;
	circleTestPos.y = 500;
	circleTestPos.raddius = 100;

	//=====================


	std::unique_ptr<Player> player(new Player);
	std::unique_ptr<StageEditor> stageEditor(new StageEditor);

	int count = 0;
	double max_y = 0;
	
	int testGh = LoadGraph("Effect.png");




	while (ProcessMessage() == 0)
	{
		//player->Update();

		//DrawBox(testPos.left, testPos.top, testPos.right, testPos.bottom, GetColor(255, 0, 0), TRUE);

		//DrawCircle(circleTestPos.x, circleTestPos.y, circleTestPos.raddius, GetColor(255, 0, 0), TRUE);

		//DrawGraph(0, 500, gh, TRUE);

		// ���������Ƃ��Ɏg��
		//if(max_y <= 50)max_y = 0.5 + count;

		//DrawRotaGraph3(500, 500, 20, 20, 0.5f + sin(3.14f * 2 / 240 * count) * 0.1f, max_y, 50, testGh, TRUE);
		//DrawRotaGraph3(600, 700, 20, 20, 0.5f + sin(3.14f * 2 / 240 * count) * 0.1f, max_y, 90, testGh, TRUE);
		//DrawRotaGraph3(300, 300, 20, 20, 0.5f + sin(3.14f * 2 / 240 * count) * 0.1f, max_y, 128, testGh, TRUE);
		//count++;

		stageEditor->Update();

		Input::Instance()->InputMemory(); // Input���X�V
		ScreenFlip();	//����ʂ�\��ʂɃR�s�[
		ClearDrawScreen();	//����ʏ���
	}

	DxLib_End();

	return 0;
}