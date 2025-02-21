#include "Gage.h"
#include "DxLib.h"
#include <stdlib.h>

#define GAGE_MAX (100)			// ゲージの上限
#define GAGE_MIN (0)			// ゲージの下限

Gage::Gage() :
	meter(0),
	fluctuation(0),
	change_flip_flag(false),
	decision(false)
{
}

Gage::~Gage()
{
}

// 初期化処理
void Gage::Initialize()
{
	// メーターの初期化
	meter = 0;

	// 変動値のランダム取得
	//fluctuation = rand() % 6 + 1;
	fluctuation = 1;

	change_flip_flag = false;

	decision = false;
}

// 更新処理
void Gage::Update()
{
	// 入力更新
	PAD_INPUT::UpdateKey();

	// Aボタンが押されたら値を変動しないようにする
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		decision = true;
	}

	// Aボタンが押されていなかったらゲージを動かす
	if (!decision)
	{
		ChangeMove();
	}
}

// 描画処理
void Gage::Draw()
{
	// ゲージの動く部分を描画
	DrawBox(100, 200, 100, 200 - meter, GetColor(255, 0, 0), false);
}

// 終了処理
void Gage::Finalize()
{

}

// ゲージの変動処理
void Gage::ChangeMove()
{
	// ゲージ変動
	meter += fluctuation;

	// ゲージが上昇するか下降するかの判定
	if (change_flip_flag == false)
	{
		// ゲージがMax以上になったら
		if (meter >= GAGE_MAX)
		{
			meter = GAGE_MAX;			// 上限にする
			fluctuation *= -1;			// 変動値の反転
			change_flip_flag = true;	// ゲージを下降にする
		}
	}
	else
	{
		// ゲージがMin以下になったら
		if (meter <= GAGE_MIN)
		{
			meter = GAGE_MIN;			// 下限にする
			fluctuation *= -1;			// 変動値の反転
			change_flip_flag = false;	// ゲージを上昇にする
		}
	}
}
