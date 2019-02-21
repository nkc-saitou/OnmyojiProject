#pragma once

/*
///////////////////////////////////////////
Singletonクラス

概要：シングルトンにしたいクラスに継承させる

使用例：Inputクラスに継承させたい場合
class Input : public Singleton <Input>

使用例２：シングルトンを継承したInputクラスのButtonDown関数を使いたい場合
Input::Instance()->ButtonDown(keyCode)
///////////////////////////////////////////
*/

template <typename _T>
class Singleton
{
protected:
	Singleton(){}
	virtual ~Singleton(){}
	Singleton(const Singleton& r){}
	Singleton& operator = (const Singleton& r){}

public:
	static _T* Instance() {
		static _T inst;
		return &inst;
	};
};