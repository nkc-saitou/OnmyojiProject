#include <memory>

#include "DxLib.h"
#include "Input.h"
#include "FpsFix.h"
#include "Control.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 1920x1080
	const int screenSizeX = 1920;
	const int screenSizeY = 1080;

	//ウィンドウ表示
	ChangeWindowMode(true);
	SetMainWindowText("陰陽師");
	SetGraphMode(screenSizeX, screenSizeY, 32);//画面サイズ指定

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1) return -1;	//エラーが起きたら終了

	// 全ての動きを管理するクラス
	std::unique_ptr<Control> control(new Control);

	//ダブルバッファリング
	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0)
	{
		control->Update();

		FpsFix::Instance()->Updata();     // FPS固定
		Input::Instance()->InputMemory(); // Inputを更新

		ScreenFlip();	//裏画面を表画面にコピー
		ClearDrawScreen();	//裏画面消す
	}

	DxLib_End();

	return 0;
}