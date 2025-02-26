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
	SetFontSize(30);
	/*DrawFormatString(50, 50, GetColor(255, 255, 255),"操作説明");
	DrawFormatString(200, 200, GetColor(255, 255, 255), "Aボタン：撃つ");
	DrawFormatString(200, 250, GetColor(255, 255, 255), "左スティックor十字キー：照準の操作");*/
	DrawFormatString(580, 680, GetColor(0, 0, 0), "←　2");
	DrawFormatString(1000, 680, GetColor(0, 0, 0), "B：戻る");
}