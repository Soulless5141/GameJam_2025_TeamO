#include "Result.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include"../../Objects/Mato/Mato.h"
#include "DxLib.h"



Result::Result() : back_ground(NULL), score(0), mileage(0)
{

}

Result::~Result()
{

}

//初期化処理
void Result::Initialize()
{
	//画像の読み込み
	back_ground = LoadGraph("Resource/images/score_bgi.jpg");

	//ゲーム結果の読み込み
	ReadResultData();
}

//更新処理
eSceneType Result::Update(const float& delta_second)
{

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return eTitle;
	}


	return GetNowSceneType();
}

//描画処理
void Result::Draw() const
{
	//背景画像を描画
	DrawRotaGraph(640, 360, 0.77, 0, back_ground, 0, 0);

	//スコアの描画
	SetFontSize(64);
	DrawFormatString(200, 390, 0x000000, "      = %6d", score);

	SetFontSize(48);
	DrawFormatString(1000, 600, GetColor(0, 0, 0), "B：戻る");
}
//終了時処理
void Result::Finalize()
{

}

//現在シーン情報を取得
eSceneType const Result::GetNowSceneType() const
{
	//スコアが5位以上ならでランキングに遷移する
	for (int i = 0; i < 5; i++)
	{
		if (score > r_score[i])
		{
			return eSceneType::eRanking_Input;
		}
	}

	return eSceneType::eResult;
}

//リザルトデータの読み込み
void Result::ReadResultData()
{
	//ファイルオープン
	FILE* fp = nullptr;
	errno_t result = fopen_s(&fp, "Resource/Data/result.csv", "r");

	//エラーチェック
	if (result != 0)
	{
		throw("Resource/Data/result.csvが読み込めません\n");
	}

	//結果を読み込む
	fscanf_s(fp, "%6d,\n", &score);

	//ファイルクローズ
	fclose(fp);
}

void Result::ReadRankingData()
{
	//ファイルオープン
	FILE* fp = nullptr;
	errno_t result = fopen_s(&fp, "Resource/Data/ranking_data.csv", "r");

	//エラーチェック
	if (result != 0)
	{
		throw("Resource/Data/ranking_data.csvが読み込めません\n");
	}

	//結果を読み込む
	for (int i = 0; i < 5; i++)
	{
		int rank[5];
		char str[256] = {};
		fscanf_s(fp, "%d,%d,%[^,]\n", &r_score[i], &rank[i], str[i], 256);
	}
	
	//ファイルクローズ
	fclose(fp);
}