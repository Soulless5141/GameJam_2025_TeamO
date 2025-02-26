#include "Result.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

//int result_background_image;  //背景設定用の変数
//int result_bgm;               //BGM設定用の変数
//
//void ResultSceneInit(void)
//{
//
//}
//
//eSceneType ResultSceneUpdate(void)
//{
//	return eResult;
//}
//
//void ResultSceneDraw(void)
//{
//	DrawFormatString(100, 100, GetColor(255, 255, 255), "リザルト画面");
//}

Result::Result() : back_ground(NULL), score(0), mileage(0)
{
	//for (int i = 0; i < 3; i++)
	//{
	//	enemy_image[i] = NULL;
	//	enemy_count[i] = NULL;
	//}
}

Result::~Result()
{

}

//初期化処理
void Result::Initialize()
{
	//画像の読み込み
	//back_ground = LoadGraph("Resource/images/back.bmp");

	//ゲーム結果の読み込み
	ReadResultData();
}

//更新処理
eSceneType Result::Update(const float& delta_second)
{

	//Bボタンでランキングに遷移する
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return eSceneType::eRanking_Input;
	}

	return GetNowSceneType();
}

//描画処理
void Result::Draw() const
{
	//背景画像を描画
	//DrawGraph(0, 0, back_ground, TRUE);


	DrawFormatString(180, 290, 0x000000, "      = %6d", score);
}
//終了時処理
void Result::Finalize()
{

}

//現在シーン情報を取得
eSceneType const Result::GetNowSceneType() const
{
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