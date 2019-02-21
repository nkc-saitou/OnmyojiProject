#pragma once

/*
///////////////////////////////////////////
Singleton�N���X

�T�v�F�V���O���g���ɂ������N���X�Ɍp��������

�g�p��FInput�N���X�Ɍp�����������ꍇ
class Input : public Singleton <Input>

�g�p��Q�F�V���O���g�����p������Input�N���X��ButtonDown�֐����g�������ꍇ
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