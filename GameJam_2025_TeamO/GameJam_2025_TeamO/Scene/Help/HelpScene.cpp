#include "HelpScene.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

//int help_background_image;  //背景設定用の変数
//int help_bgm;               //BGM設定用の変数

int help_scope;
int help_nuigurumi;
int help_bullet;

//ヘルプ画面の初期化
void HelpSceneInit(void)
{
	help_scope = LoadGraph("Resource/Images/scope.png");
	help_nuigurumi = LoadGraph("Resource/Images/keihin1.png");
	help_bullet = LoadGraph("Resource/Images/bullet.png");
}

//ヘルプ画面のアップデート
eSceneType HelpSceneUpdate(void)
{
	int key_help = GetJoypadInputState(DX_INPUT_PAD1);

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return eTitle;
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT))
	{
		return eHelp2;
	}

	return eHelp;
}

//ヘルプ画面の描画
void HelpSceneDraw(void)
{
	DrawFormatString(50, 50, GetColor(255, 255, 255), "ヘルプ画面");
	DrawFormatString(900, 600, GetColor(255, 255, 255), "B：戻る");
	DrawFormatString(640, 600, GetColor(255, 255, 255), "1　→");

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "弾は５発、打ち切ったら終了");
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲージをためて...");
}