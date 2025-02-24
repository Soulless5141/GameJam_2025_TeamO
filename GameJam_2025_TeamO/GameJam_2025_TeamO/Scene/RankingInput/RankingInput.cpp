#include "RankingInput.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

//int RankingInput_background_image;
//
//void RankingInputSceneInit(void)
//{
//
//}
//
//eSceneType RankingInputSceneUpdate()
//{
//	return eRanking_Input;
//}
//
//void RankingInputSceneDraw(void)
//{
//
//}

RankingInputScene::RankingInputScene() : background_image(NULL),
ranking(nullptr), score(0), name_num(0), cursor_x(0), cursor_y(0),
rankinginput_bgm(NULL), select_se(NULL), decision_se(NULL)
{
	memset(name, NULL, (sizeof(char) * 15));
}

RankingInputScene::~RankingInputScene()
{

}

//初期化処理
void RankingInputScene::Initialize()
{
	////画像の読み込み
	//background_image = LoadGraph("Resource/images/Ranking.png");

	////BGMの読み込み
	//rankinginput_bgm = LoadSoundMem("Resource/bgm/RankingInputBGM.wav");

	////カーソル音読み込み
	//select_se = LoadSoundMem("Resource/se/select.wav");
	////決定音読み込み
	//decision_se = LoadSoundMem("Resource/se/decision.wav");

	////エラーチェック
	//if (background_image == -1)
	//{
	//	throw("Resource/images/Ranking.pngがありません\n");
	//}

	//if (rankinginput_bgm == -1)
	//{
	//	throw("Resource/bgm/RankingInputBGM.wavがありません\n");
	//}

	//if (select_se == -1)
	//{
	//	throw("Resource/bgm/select.wavがありません\n");
	//}

	//if (decision_se == -1)
	//{
	//	throw("Resource/se/decision.wav.wavがありません\n");
	//}


	//メモリの動的確保
	ranking = new RankingData;
	ranking->Initialize();

	//リザルトデータを取得する
	FILE* fp = nullptr;
	//ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "r");

	//エラーチェック
	if (result != 0)
	{
		throw("Resource/dat/result_data.csvが読み込めません\n");
	}

	//結果を読み込む
	fscanf_s(fp, "%6d,\n", &score);

	//ファイルクローズ
	fclose(fp);
}

//更新処理
eSceneType RankingInputScene::Update()
{
	bool is_change = false;

	//BGM再生
	PlaySoundMem(rankinginput_bgm, DX_PLAYTYPE_LOOP, FALSE);

	//名前入力処理
	is_change = InputName();

	//シーン変更は可能か？
	if (is_change)
	{
		//ランキング表示に遷移
		return eSceneType::eRanking_Input;
	}
	else
	{
		return GetNowScene();
	}
}

//描画処理
void RankingInputScene::Draw() const
{
	//背景画像の描画
	DrawGraph(0, 0, background_image, TRUE);

	//名前入力指示文字列


	SetFontSize(48);
	DrawString(140, 50, "ランキング登録", 0x000000);

	SetFontSize(16);
	//DrawString(150, 100, "ランキングに登録します", 0x000000);
	DrawFormatString(100, 220, GetColor(0, 0, 0), ">%s", name);

	//選択文字を描画
	const int font_size = 25;
	for (int i = 0; i < 26; i++)
	{
		int x = (i % 13) * font_size + 15;
		int y = (i / 13) * font_size + 300;
		DrawFormatString(x, y, GetColor(0, 0, 0), "%-3c", 'a' + i);
		y = ((i / 13) + 2) * font_size + 300;
		DrawFormatString(x, y, GetColor(0, 0, 0), "%-3c", 'A' + i);
	}
	DrawString(40, 405, "決定", GetColor(0, 0, 0));
	DrawString(40 + font_size * 2, 405, "消す", GetColor(0, 0, 0));

	//選択文字をフォーカスする
	if (cursor_y < 4)
	{
		int x = cursor_x * font_size + 10;
		int y = cursor_y * font_size + 295;
		DrawBox(x, y, x + font_size, y + font_size, GetColor(0, 0, 0), FALSE);
	}
	else
	{
		if (cursor_x == 0)
		{
			DrawBox(35, 400, 35 + font_size * 2, 400 + font_size, GetColor(0, 0, 0), FALSE);
		}
		else
		{
			DrawBox(85, 400, 85 + font_size * 2, 400 + font_size, GetColor(0, 0, 0), FALSE);
		}
	}
}

//終了時処理
void RankingInputScene::Finalize()
{
	//ランキングにデータを格納
	ranking->SetRankingData(score, name);

	//読み込んだ画像を削除
	DeleteGraph(background_image);

	//読み込んだBGMの削除
	DeleteSoundMem(rankinginput_bgm);

	//読み込んだSEを削除
	DeleteSoundMem(select_se);
	DeleteSoundMem(decision_se);

	//動的メモリの解放
	delete ranking;
}

//現在のシーン情報を取得
eSceneType RankingInputScene::GetNowScene() const
{
	return eSceneType::eRanking_Input;
}

//名前入力処理
bool RankingInputScene::InputName()
{
	// 入力情報取得
	int Key = GetJoypadInputState(DX_INPUT_PAD1);

	//カーソル操作処理
	if (Key & XINPUT_BUTTON_DPAD_LEFT)
	{
		// カーソル音鳴らす
		PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
		if (cursor_x > 0)
		{
			cursor_x--;
		}
		else
		{
			cursor_x = 12;
		}
	}
	if (Key & XINPUT_BUTTON_DPAD_RIGHT)
	{
		// カーソル音鳴らす
		PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
		if (cursor_x < 12)
		{
			cursor_x++;
		}
		else
		{
			cursor_x = 0;
		}
	}
	// 入力文字数が14文字未満だったら
	if (name_num < 14) {
		if (Key & XINPUT_BUTTON_DPAD_UP)
		{
			if (cursor_y > 0)
			{
				// カーソル音鳴らす
				PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
				cursor_y--;
			}
		}
		if (Key & XINPUT_BUTTON_DPAD_DOWN)
		{
			if (cursor_y < 4)
			{
				// カーソル音鳴らす
				PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
				cursor_y++;
				if (cursor_y == 4)
				{
					cursor_x = 0;
				}
			}
		}
	}

	//カーソル位置の文字を決定する
	if (Key & Key & PAD_INPUT_A)
	{
		// 決定音鳴らす
		PlaySoundMem(decision_se, DX_PLAYTYPE_BACK, TRUE);
		if (cursor_y < 2)
		{
			name[name_num++] = 'a' + cursor_x + (cursor_y * 13);
			if (name_num == 14)
			{
				cursor_x = 0;
				cursor_y = 4;
			}
		}
		else if (cursor_y < 4)
		{
			name[name_num++] = 'A' + cursor_x + ((cursor_y - 2) * 13);
			if (name_num == 14)
			{
				cursor_x = 0;
				cursor_y = 4;
			}
		}
		else
		{
			if (cursor_x == 0) // 決定ボタン
			{
				name[name_num] = '\0';
				return true;
			}
			else // 戻るボタン
			{
				if (name_num > 0)
				{
					name_num--;
					name[name_num] = NULL;
				}
			}
		}
	}
	return false;
}