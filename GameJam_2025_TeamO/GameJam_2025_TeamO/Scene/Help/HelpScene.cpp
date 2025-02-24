#include "HelpScene.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int help_background_image;  //背景設定用の変数
int help_bgm;               //BGM設定用の変数

//ヘルプ画面の初期化
void HelpSceneInit(void)
{

}

//ヘルプ画面のアップデート
eSceneType HelpSceneUpdate(void)
{
	int key_help = GetJoypadInputState(DX_INPUT_PAD1);

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return eTitle;
	}
	return eHelp;
}

//ヘルプ画面の描画
void HelpSceneDraw(void)
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "ヘルプ画面");
}