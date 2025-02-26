#include "Title.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int title_background_image;  //背景設定用の変数
int sentaku_img;                 //決定音
int idou_bgm;                    //移動音
int kettei_bgm;                  //決定音
int title_bgm;               //BGM設定用の変数
int cursor_number = eStart_Title;

//タイトル画面の初期化
void TitleSceneInit(void)
{
	title_background_image = LoadGraph("Resource/Images/Title.jpg");
	sentaku_img = LoadGraph("Resource/Images/bullet.png");
	kettei_bgm = LoadSoundMem("Resource/Sounds/決定ボタンを押す3.mp3");
	idou_bgm = LoadSoundMem("Resource/Sounds/カーソル移動5.mp3");
	title_bgm = LoadSoundMem("Resource/Sounds/yomatsuri.mp3");

	PlaySoundMem(title_bgm, DX_PLAYTYPE_LOOP, TRUE);
}

//タイトル画面のアップデート
eSceneType TitleSceneUpdate()
{
	int key_title = GetJoypadInputState(DX_INPUT_PAD1);

	//選択
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		PlaySoundMem(kettei_bgm, DX_PLAYTYPE_BACK,TRUE); //音源の再生

		//シーンの切り替え
		if (cursor_number == eStart_Title)
		{
			DeleteSoundMem(title_bgm);
			return eSelectMode;
		}
		else if (cursor_number == eHelp_Title)
		{
			DeleteSoundMem(title_bgm);
			return eHelp;
		}
		else if (cursor_number == eRanking_title)
		{
			DeleteSoundMem(title_bgm);
			return eRanking_Scene;
		}
		else if (cursor_number == eEnd_title)
		{
			DeleteSoundMem(title_bgm);
			return eEnd;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		//音源の再生
		//PlaySoundMem(title_bgm, DX_PLAYTYPE_NORMAL, TRUE);
		PlaySoundMem(idou_bgm, DX_PLAYTYPE_BACK, TRUE);

		cursor_number++;

		if (cursor_number > 3)
		{
			cursor_number = eStart_Title;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		PlaySoundMem(idou_bgm, DX_PLAYTYPE_BACK, TRUE);
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
	DrawRotaGraph(640, 360, 0.77, 0, title_background_image, 0, 0);

	/*描画する文字*/
	SetFontSize(30);
	DrawFormatString(580,500,GetColor(0,0,0), "スタート");
	DrawFormatString(580,530, GetColor(0, 0, 0),"ヘルプ");
	DrawFormatString(580,560, GetColor(0, 0, 0),"ランキング");
	DrawFormatString(580,590, GetColor(0, 0, 0),"エンド");

	DrawRotaGraph(530, 515 + cursor_number * 31, 0.1, 12.55, sentaku_img, TRUE, TRUE);
	//DrawCircle(550, 510 + cursor_number * 30, 15, GetColor(0, 0, 0), TRUE);
}