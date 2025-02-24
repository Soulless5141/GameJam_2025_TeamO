#include "Title.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int title_background_image;  //背景設定用の変数
int title_bgm;               //BGM設定用の変数
int cursor_number;

//タイトル画面の初期化
void TitleSceneInit(void)
{
	cursor_number = eStart_Title;
}

//タイトル画面のアップデート
eSceneType TitleSceneUpdate()
{
	int key_title = GetJoypadInputState(DX_INPUT_PAD1);

	//選択
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		if (cursor_number == eStart_Title)
		{
			return eSelectMode;
		}
		else if (cursor_number == eHelp_Title)
		{
			return eHelp;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		cursor_number++;

		if (cursor_number > 1)
		{
			cursor_number = eStart_Title;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		cursor_number--;

		if (cursor_number < 0)
		{
			cursor_number = eHelp_Title;
		}
	}

	return eTitle;
}

//タイトル画面の描画
void TitleSceneDraw(void)
{
	/*描画する文字*/
	SetFontSize(30);
	DrawFormatString(500,470,GetColor(255,255,255), "スタート");
	DrawFormatString(500,500, GetColor(255, 255, 255),"ヘルプ");
	DrawFormatString(500,530, GetColor(255, 255, 255),"ランキング");
	DrawFormatString(500,560, GetColor(255, 255, 255),"エンド");
	DrawCircle(450, 480 + cursor_number * 30, 15, GetColor(255, 255, 255), TRUE);
}