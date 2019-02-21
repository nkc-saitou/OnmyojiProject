#pragma once

/*
///////////////////////////////////////////
Inputクラス

概要　：入力関連の処理をまとめてあります。
使用例：Input::Instance()->ButtonDown(keyCode)
注意　：Mainループ内でInputMemory()を呼び、過去情報の取得を毎フレーム行う
///////////////////////////////////////////
*/

#include "DxLib.h"
#include "Singleton.h"

//ボタン総数
#define PAD_BUTTON_NUM 16

//キーボード入力用バッファサイズ
#define KEY_STATE_BUFFER_SIZE 256

//パッドの対応番号
enum PadType
{
	Pad_1 = 1,
	Pad_2,
	Pad_3,
	Pad_4,
	Pad_5,
	Pad_6,
	Pad_7,
	Pad_8,
	Pad_9,
	Pad_10,
	Pad_11,
	Pad_12,
	Pad_13,
	Pad_14,
	Pad_15,
	Pad_16
};

class Input : public Singleton <Input>
{
	//パッドの入力状態を格納
	XINPUT_STATE input[MAX_JOYPAD_NUM];
	XINPUT_STATE oldInput[MAX_JOYPAD_NUM];

	//マウスの入力状態を格納
	int mouse;
	int oldMouse;

	//キーの入力状態を格納
	char oldKey[KEY_STATE_BUFFER_SIZE];
	char key[KEY_STATE_BUFFER_SIZE];

	//全ての入力状態を格納
	int allInput;
	int oldAllInput;

	//対応パッド
	int padInput = 0;

	//パッド配列の添字用配列
	int padInputNum;

	//入力角度を保存
	int InputX, InputY;

	//入力状態を更新
	void InputSetting();

	//各パッドの入力状態を更新
	void PadInputSetting(int padType);

	//引数に与えられたkeyCodeとpadTypeが処理範囲内かどうかを判断
	bool InputCheck(int keyCode, int padType = 0);

public:

	//過去の入力情報の取得
	void InputMemory();
	
	//入力角度の取得
	int AngleInputX(int padType);
	int AngleInputY(int padType);

	XINPUT_STATE PadState(int padType);

	//パッドを振動させる
	void PadStartVibration(int padType, int Power = 1000, int Time = -1);

	//振動しているパッドを止める
	void PadStopVibration(int padType);

	//===引数で渡したkeyCode,padType通りにを入力していたら===

	//ボタンを押した瞬間
	bool ButtonDown(int keyCode, int padType = 0); 

	//ボタンを押しているとき
	bool Button(int keyCode, int padType = 0); 

	//ボタンを離した瞬間
	bool ButtonUp(int keyCode, int padType = 0); 


	//=====とにかく何かを入力をしていたら=====

	//何らかのボタンを押しているとき
	bool AnyButton();

	//何らかのボタンを押した瞬間
	bool AnyButtonDown();

	//何らかのボタンを離した瞬間
	bool AnyButtonUp();


	//=====接続されているパッドのうち、どれか一つでも引数のkeyCodeを入力していたら=====

	//どれかのパッドが指定のボタンを押しているとき
	bool PadAnyButton(int keyCode);

	//どれかのパッドが指定のボタンを押した瞬間
	bool PadAnyButtonDown(int keyCode);

	//どれかのパッドが指定のボタンを離した瞬間
	bool PadAnyButonUp(int keyCode);
};
