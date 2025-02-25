#include "HelpScene2.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

void HelpScene2Init(void)
{

}

eSceneType HelpScene2Update(void)
{
	int key_help2 = GetJoypadInputState(DX_INPUT_PAD1);

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return eTitle;
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_LEFT))
	{
		return eHelp;
	}

	return eHelp2;
}

void HelpScene2Draw(void)
{
	DrawFormatString(50, 50, GetColor(255, 255, 255),"ëÄçÏê‡ñæ");
	DrawFormatString(580, 600, GetColor(255, 255, 255), "Å©Å@2");
	DrawFormatString(900, 600, GetColor(255, 255, 255), "BÅFñﬂÇÈ");
}