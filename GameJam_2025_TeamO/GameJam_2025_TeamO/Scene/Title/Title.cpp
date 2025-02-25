#include "Title.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int title_background_image;  //背景設定用の変数
int title_bgm;               //BGM設定用の変数
int cursor_number = eStart_Title;

//タイトル画面の初期化
void TitleSceneInit(void)
{
	title_background_image = LoadGraph("Resource/Images/Title.png");
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
		else if (cursor_number == eRanking_title)
		{
			return eRanking;
		}
		else if (cursor_number == eEnd_title)
		{
			return eEnd;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		cursor_number++;

		if (cursor_number > 3)
		{
			cursor_number = eStart_Title;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		cursor_number--;

		if (cursor_number < 0)
		{
			cursor_number = eEnd_title;
		}
	}

	return eTitle;
}

//タイトル画面の描画
void TitleSceneDraw(void)
{
	/*描画する画像*/
	DrawGraph(230, 0, title_background_image, TRUE);

	/*描画する文字*/
	SetFontSize(30);
	DrawFormatString(580,470,GetColor(0,0,0), "スタート");
	DrawFormatString(580,500, GetColor(0, 0, 0),"ヘルプ");
	DrawFormatString(580,530, GetColor(0, 0, 0),"ランキング");
	DrawFormatString(580,560, GetColor(0, 0, 0),"エンド");
	DrawCircle(550, 480 + cursor_number * 30, 15, GetColor(0, 0, 0), TRUE);
}