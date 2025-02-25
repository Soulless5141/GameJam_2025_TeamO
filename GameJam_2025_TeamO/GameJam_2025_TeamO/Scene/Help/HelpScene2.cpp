#include "HelpScene2.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int help2_img;

void HelpScene2Init(void)
{
	help2_img = LoadGraph("Resource/Images/Help2.jpg");
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
	DrawRotaGraph(640, 360, 0.77, 0, help2_img, 0, 0);
	DrawFormatString(50, 50, GetColor(255, 255, 255),"ëÄçÏê‡ñæ");
	DrawFormatString(580, 680, GetColor(255, 255, 255), "Å©Å@2");
	DrawFormatString(900, 680, GetColor(255, 255, 255), "BÅFñﬂÇÈ");
}