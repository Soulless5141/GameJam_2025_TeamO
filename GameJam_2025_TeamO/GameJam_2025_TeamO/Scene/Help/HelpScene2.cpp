#include "HelpScene2.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int help2_img;  //背景画像
int help2_kettei;  //決定音
int help2_idou;    //移動音

void HelpScene2Init(void)
{
	help2_img = LoadGraph("Resource/Images/Help2.jpg");
	help2_idou = LoadSoundMem("Resource/Sounds/カーソル移動5.mp3");
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
		PlaySoundMem(help2_idou, DX_PLAYTYPE_BACK, TRUE);
		return eHelp;
	}

	return eHelp2;
}

void HelpScene2Draw(void)
{
	DrawRotaGraph(640, 360, 0.77, 0, help2_img, 0, 0);
	SetFontSize(30);
	DrawFormatString(580, 680, GetColor(0, 0, 0), "←　2");
	DrawFormatString(1000, 680, GetColor(0, 0, 0), "B：戻る");
}