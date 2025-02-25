#include "RankingScene.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

RankingScene::RankingScene() : background_image(NULL), ranking(nullptr)
{

}

RankingScene::~RankingScene()
{

}

//初期化処理
void RankingScene::Initialize()
{
	//画像の読み込み
	//background_image = LoadGraph("Resource/images/Ranking.png");

	////エラーチェック
	//if (background_image == -1)
	//{
	//	throw("Resource/images/Ranking.pngがありません\n");
	//}

	//ランキング情報を取得
	ranking = new RankingData;
	ranking->Initialize();
}

//更新処理
eSceneType RankingScene::Update(const float& delta_second)
{
	// 入力情報取得
	int Key = GetJoypadInputState(DX_INPUT_PAD1);

	//Bボタンが押されたら、タイトルに戻る
	if (Key & PAD_INPUT_B)
	{
		return eSceneType::eTitle;
	}
	return GetNowSceneType();
}

//描画処理
void RankingScene::Draw() const
{
	//背景画像の描画
	//DrawGraph(0, 0, background_image, FALSE);
	DrawBox(0, 0, 1000, 700, GetColor(255, 255, 255), true);

	SetFontSize(48);
	DrawString(200, 50, "ランキング", 0x000000);


	SetFontSize(16);

	//取得したランキングデータを描画する
	for (int i = 0; i < 5; i++)
	{
		DrawFormatString(50, 170 + i * 25, 0x000000, "%2d %6d %-15s", ranking->GetRank(i), ranking->GetScore(i), ranking->GetName(i));
	}
}

//終了処理
void RankingScene::Finalize()
{
	//読み込んだ画像の削除
	DeleteGraph(background_image);

	//動的メモリの解放
	ranking->Finalize();
	delete ranking;
}

//現在のシーン情報を取得
const eSceneType RankingScene::GetNowSceneType() const
{
	return eSceneType::eRanking_Scene;
}