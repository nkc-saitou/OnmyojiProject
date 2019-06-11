#pragma once
#include "Singleton.h"
#include "E_SceneState.h"

/*
///////////////////////////////////////////
FadeManager�N���X

�T�v�@�F�t�F�[�h�C���A�E�g�𐧌䂷��N���X
///////////////////////////////////////////
*/
class FadeManager : public Singleton <FadeManager>
{

	int c = 0;
public:

	bool IsWhiteFadeIn();
	bool IsWhiteFadeOut();

	void ResetFadeValue();
};