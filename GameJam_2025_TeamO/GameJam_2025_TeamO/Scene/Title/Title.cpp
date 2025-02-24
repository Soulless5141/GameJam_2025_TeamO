#include "Title.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int title_background_image;  //背景設定用の変数
int title_bgm;               //BGM設定用の変数

//タイトル画面の初期化
void TitleSceneInit(void)
{

}

//タイトル画面のアップデート
eSceneType TitleSceneUpdate()
{
	int key_title = GetJoypadInputState(DX_INPUT_PAD1);

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return eHelp;
	}

	return eTitle;
}

//タイトル画面の描画
void TitleSceneDraw(void)
{
	/*描画する文字*/
	SetFontSize(30);
	DrawFormatString(100,500,GetColor(255,255,255), "スタート");
	DrawFormatString(500,500, GetColor(255, 255, 255),"ヘルプ");
}