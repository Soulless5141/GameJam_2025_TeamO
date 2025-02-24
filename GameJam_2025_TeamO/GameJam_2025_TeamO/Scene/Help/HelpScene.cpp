#include "HelpScene.h"
#include "../SceneType.h"
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
	return eHelp;
}

//ヘルプ画面の描画
void HelpSceneDraw(void)
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "ヘルプ画面");
}