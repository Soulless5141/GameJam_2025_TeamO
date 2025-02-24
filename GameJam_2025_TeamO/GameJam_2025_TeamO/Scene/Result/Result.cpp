#include "Result.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int result_background_image;  //背景設定用の変数
int result_bgm;               //BGM設定用の変数

void ResultSceneInit(void)
{

}

eSceneType ResuleUpdate(void)
{
	return eResult;
}

void ResultSceneDraw(void)
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "リザルト画面");
}