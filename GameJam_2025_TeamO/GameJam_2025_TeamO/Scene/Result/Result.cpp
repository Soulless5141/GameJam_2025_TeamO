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

	num_img[0] = LoadGraph("Resource/Images/Number/0.png");
	num_img[1] = LoadGraph("Resource/Images/Number/1.png");
	num_img[2] = LoadGraph("Resource/Images/Number/2.png");
	num_img[3] = LoadGraph("Resource/Images/Number/3.png");
	num_img[4] = LoadGraph("Resource/Images/Number/4.png");
	num_img[5] = LoadGraph("Resource/Images/Number/5.png");
	num_img[6] = LoadGraph("Resource/Images/Number/6.png");
	num_img[7] = LoadGraph("Resource/Images/Number/7.png");
	num_img[8] = LoadGraph("Resource/Images/Number/8.png");
	num_img[9] = LoadGraph("Resource/Images/Number/9.png");

	score = 345;

	////エラーチェック
	//if (back_ground == -1)
	//{
	//	throw("Resource/images/back.bmpがありません\n");
	//}
	//if (enemy_image[0] == -1)
	//{
	//	throw("Resource/images/Enemy1.pngがありません\n");
	//}
	//if (enemy_image[1] == -1)
	//{
	//	throw("Resource/images/Enemy2.pngがありません\n");
	//}
	//if (enemy_image[2] == -1)
	//{
	//	throw("Resource/images/Enemy3.pngがありません\n");
	//}

	//ゲーム結果の読み込み
	//ReadResultData();
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

	//スコア等表示領域
	DrawBox(150, 150, 490, 330, GetColor(0, 153, 0), TRUE);
	DrawBox(150, 150, 490, 330, GetColor(0, 0, 0), FALSE);

	//スコア画像の描画
	DrawRotaGraph(10, 0, 0.2, 0, num_img[score/100], 0, 0);  //100の位
	DrawRotaGraph(10, 10, 0.2, 0, num_img[score/10], 0, 0);   //10の位
	DrawRotaGraph(10, 15, 0.2, 0, num_img[score/1], 0, 0);    //1の位

	/*DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);

	SetFontSize(20);
	DrawString(220, 170, "ゲームオーバー", GetColor(204, 0, 0));
	SetFontSize(16);
	DrawString(180, 200, "走行距離       ", GetColor(0, 0, 0));
	DrawFormatString(250, 200, 0xFFFFFF, "             = %6d", mileage);
	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph(230, 230 + (i * 20), 0.4f, 0.0, enemy_image[i], TRUE);
		DrawFormatString(260, 222 + (i * 21), GetColor(255, 255, 255), "%6d x%4d=%6d,",
			enemy_count[i], (i + 1) * 500, (i + 1) * 500 * enemy_count[i]);
	}
	DrawString(180, 290, "スコア", GetColor(0, 0, 0));
	DrawFormatString(180, 290, 0xFFFFFF, "      = %6d", score);*/
}
//終了時処理
void Result::Finalize()
{
	////読み込んだ画像を削除
	//DeleteGraph(back_ground);
	//for (int i = 0; i < 3; i++)
	//{
	//	DeleteGraph(enemy_image[i]);
	//}
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
	errno_t result = fopen_s(&fp, "Resource/dat/result.csv", "r");

	//エラーチェック
	if (result != 0)
	{
		throw("Resource/dat/result.csvが読み込めません\n");
	}

	//結果を読み込む
	fscanf_s(fp, "%6d,\n", &score);

	////避けた数と点数を取得
	//for (int i = 0; i < 3; i++)
	//{
	//	fscanf_s(fp, "%6d\n", &enemy_count[i]);
	//}

	//fscanf_s(fp, "%6d\n", &mileage);

	//ファイルクローズ
	fclose(fp);
}