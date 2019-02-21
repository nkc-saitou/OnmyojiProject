#include "Input.h"

/////////////////////////////////////////////////////
//引数			:入力キーコード、対応パッド(デフォルト引数は０(キー入力))
//戻り値		:引数のキーが押されていればtrue
//動作			:引数のキーが押されているかを判定
/////////////////////////////////////////////////////
bool Input::Button(int keyCode, int padType)
{
	//無効な数値が入力されていないかどうか
	if (InputCheck(keyCode, padType) == false) return false;

	//入力状態を更新
	InputSetting();
	PadInputSetting(padType);

	//キー入力処理
	if(key[keyCode] != 0) return true;

	//マウス入力処理
	if ((mouse & keyCode) == keyCode) return true;

	//パッド入力処理
	if (input[padInputNum].Buttons[keyCode] != 0) return true;

	return false;
}

/////////////////////////////////////////////////////
//引数			:入力キーコード、対応パッド(デフォルト引数は０(キー入力))
//戻り値		:引数のキーが押された瞬間のみtrue
//動作			:引数のキーが押された瞬間を判定
/////////////////////////////////////////////////////
bool Input::ButtonDown(int keyCode, int padType)
{
	//無効な数値が入力されていないかどうか
	if (InputCheck(keyCode, padType) == false) return false;

	//入力状態を更新
	InputSetting();
	PadInputSetting(padType);

	//キー入力処理
	if (oldKey[keyCode] == 0 &&
		key[keyCode] != 0) return true;

	//マウス入力処理
	if ((oldMouse & keyCode) == 0 &&
		(mouse & keyCode) == keyCode) return true;
	
	//パッド入力処理
	if (oldInput[padInputNum].Buttons[keyCode] == 0 &&
		input[padInputNum].Buttons[keyCode] != 0) return true;

	return false;
}

/////////////////////////////////////////////////////
//引数			:入力キーコード、対応パッド(デフォルト引数は０(キー入力))
//戻り値		:引数のキーが離された瞬間のみtrue
//動作			:引数のキーが離された瞬間を判定
/////////////////////////////////////////////////////
bool Input::ButtonUp(int keyCode, int padType)
{
	//無効な数値が入力されていないかどうか
	if (InputCheck(keyCode, padType) == false) return false;

	//入力状態を更新
	InputSetting();
	PadInputSetting(padType);

	//キー入力処理
	if (oldKey[keyCode] != 0 &&
		key[keyCode] == 0) return true;

	//マウス入力処理
	if ((oldMouse & keyCode) == keyCode &&
		(mouse & keyCode) == 0) return true;

	//パッド入力処理
	if (oldInput[padInputNum].Buttons[keyCode] != 0 &&
		input[padInputNum].Buttons[keyCode] == 0) return true;

	return false;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:何らかのキーが押されている時はtrue
//動作			:何かしらのキーが押されているかを判定
/////////////////////////////////////////////////////
bool Input::AnyButton()
{
	//入力状態を更新
	InputSetting();

	//押されているかを判定
	if (allInput != 0) return true;
	return false;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:何らかのキーが押された瞬間のみtrue
//動作			:何かしらのキーが押された瞬間を判定
/////////////////////////////////////////////////////
bool Input::AnyButtonDown()
{
	//入力状態を更新
	InputSetting();

	//１フレーム前と現在フレームを比べる
	if (oldAllInput == 0 &&
		allInput != 0) return true;

	return false;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:何らかのキーが離された瞬間のみtrue
//動作			:何かしらのキーが離された瞬間を判定
/////////////////////////////////////////////////////
bool Input::AnyButtonUp()
{
	//入力状態を更新
	InputSetting();

	//１フレーム前と現在フレームを比べる
	if (oldAllInput != 0 &&
		allInput == 0) return true;

	return false;
}

/////////////////////////////////////////////////////
//引数			:入力キーコード
//戻り値		:パッドボタンが押されている時true
//動作			:パッドボタンが押されているかどうかを判定
/////////////////////////////////////////////////////
bool Input::PadAnyButton(int keyCode)
{
	//全てのパッドを調べる
	for (int i = 1; i <= MAX_JOYPAD_NUM; i++)
	{
		//パッドの入力状態を調べる
		PadInputSetting(i);

		//ボタンが押されているかどうか
		if (input[padInputNum].Buttons[keyCode] != 0) return true;
	}

	return false;
}

/////////////////////////////////////////////////////
//引数			:入力キーコード
//戻り値		:引数のボタンが押された瞬間のみtrue
//動作			:接続されているどれかのパッドの、指定のボタンが押された瞬間を判定
/////////////////////////////////////////////////////
bool Input::PadAnyButtonDown(int keyCode)
{
	//全てのパッドを調べる
	for (int i = 1; i <= MAX_JOYPAD_NUM; i++)
	{
		//パッドの入力状態を調べる
		PadInputSetting(i);

		if (oldInput[padInputNum].Buttons[keyCode] == 0 &&
			input[padInputNum].Buttons[keyCode] != 0) return true;
	}

	return false;
}

/////////////////////////////////////////////////////
//引数			:入力キーコード
//戻り値		:引数のボタンが離された瞬間のみtrue
//動作			:接続されているどれかのパッドの、指定のボタンが離された瞬間を判定
/////////////////////////////////////////////////////
bool Input::PadAnyButonUp(int keyCode)
{
	//全てのパッドを調べる
	for (int i = 1; i <= MAX_JOYPAD_NUM; i++)
	{
		//パッドの入力状態を調べる
		PadInputSetting(i);

		if (oldInput[padInputNum].Buttons[keyCode] != 0 &&
			input[padInputNum].Buttons[keyCode] == 0) return true;
	}

	return false;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:現在の入力状態を格納
/////////////////////////////////////////////////////
void Input::InputSetting()
{
	//キーボードの入力状態を得る
	GetHitKeyStateAll(key);

	//マウスの入力状態を得る
	mouse = GetMouseInput();

	//全て(キーボード、マウス、パッド)の入力状態を得る
	allInput = CheckHitKeyAll(DX_CHECKINPUT_ALL);

}

/////////////////////////////////////////////////////
//引数			:振動させるパッド、振動の強さ(デフォルトは1000)、振動させる時間(デフォルトは-1(PadStopVibrationを呼ぶまで止まらない))
//戻り値		:なし
//動作			:振動させる
/////////////////////////////////////////////////////
void Input::PadStartVibration(int padType, int Power, int Time)
{
	PadInputSetting(padType);
	StartJoypadVibration(padInput, Power, Time);
}

/////////////////////////////////////////////////////
//引数			:振動をとめるパッド
//戻り値		:なし
//動作			:振動を止める
/////////////////////////////////////////////////////
void Input::PadStopVibration(int padType)
{
	PadInputSetting(padType);
	StopJoypadVibration(padInput);
}

/////////////////////////////////////////////////////
//引数			:対応パッド
//戻り値		:なし
//動作			:ジョイパッドのアナログ的なレバー入力情報のX軸を得る
/////////////////////////////////////////////////////
int Input::AngleInputX(int padType)
{
	if (padType <= 0) return 0;

	PadInputSetting(padType);

	float angleInput_x = InputX;
	
	return angleInput_x;
}

/////////////////////////////////////////////////////
//引数			:対応パッド
//戻り値		:なし
//動作			:ジョイパッドのアナログ的なレバー入力情報のY軸を得る
/////////////////////////////////////////////////////
int Input::AngleInputY(int padType)
{
	if (padType <= 0) return 0;

	PadInputSetting(padType);

	float angleInput_y = InputY;

	return angleInput_y;
}

/////////////////////////////////////////////////////
//引数			:対応パッド
//戻り値		:なし
//動作			:現在の各パッドの入力状態を格納
/////////////////////////////////////////////////////
void Input::PadInputSetting(int padType)
{
	if (padType <= 0) return;

	//対応パッドを判別
	switch (padType)
	{
	case Pad_1:  padInput = DX_INPUT_PAD1;  break;
	case Pad_2:  padInput = DX_INPUT_PAD2;  break;
	case Pad_3:  padInput = DX_INPUT_PAD3;  break;
	case Pad_4:  padInput = DX_INPUT_PAD4;  break;
	case Pad_5:  padInput = DX_INPUT_PAD5;  break;
	case Pad_6:  padInput = DX_INPUT_PAD6;  break;
	case Pad_7:  padInput = DX_INPUT_PAD7;  break;
	case Pad_8:  padInput = DX_INPUT_PAD8;  break;
	case Pad_9:  padInput = DX_INPUT_PAD9;  break;
	case Pad_10: padInput = DX_INPUT_PAD10; break;
	case Pad_11: padInput = DX_INPUT_PAD11; break;
	case Pad_12: padInput = DX_INPUT_PAD12; break;
	case Pad_13: padInput = DX_INPUT_PAD13; break;
	case Pad_14: padInput = DX_INPUT_PAD14; break;
	case Pad_15: padInput = DX_INPUT_PAD15; break;
	case Pad_16: padInput = DX_INPUT_PAD16; break;
	}

	//パッド配列に入力状態を格納するための添字
	padInputNum = padType - 1;

	// パッドの入力状態を取得
	GetJoypadXInputState(padInput, &input[padInputNum]);

	//アナログパッドの入力状態を取得
	GetJoypadAnalogInput(&InputX, &InputY, padInput);
}

/////////////////////////////////////////////////////
//引数			:入力されたキーコード、パッド(デフォルト引数は０)
//戻り値		:範囲を超えた数値だった場合false
//動作			:引数で渡された数値が処理範囲内の数値かどうかを判断
/////////////////////////////////////////////////////
bool Input::InputCheck(int keyCode, int padType)
{
	if (padType == 0 && keyCode > KEY_STATE_BUFFER_SIZE) return false;
	if (padType != 0 && keyCode > PAD_BUTTON_NUM) return false;
	if (padType > MAX_JOYPAD_NUM || padType < 0) return false;

	return true;
}

/////////////////////////////////////////////////////
//引数			:なし
//戻り値		:なし
//動作			:過去の入力情報を格納
/////////////////////////////////////////////////////
void Input::InputMemory()
{
	oldMouse = mouse;
	memcpy(oldKey, key, sizeof(key));
	memcpy(oldInput, input, sizeof(input));
	oldAllInput = allInput;
}