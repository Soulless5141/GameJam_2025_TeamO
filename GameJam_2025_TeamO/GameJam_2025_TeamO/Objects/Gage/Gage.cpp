#include "Gage.h"
#include "DxLib.h"
#include <stdlib.h>

#define GAGE_MAX (100)			// ゲージの上限
#define GAGE_MIN (1)			// ゲージの下限

Gage::Gage() :
	meter(0),
	fluctuation(0),
	change_flip_flag(false),
	decision(false)
{
	// メーターの初期化
	meter = 1;

	// 変動値のランダム取得
	fluctuation = rand() % 4 + 3;

	change_flip_flag = false;

	decision = false;
}

Gage::~Gage()
{
}

// 初期化処理
void Gage::Initialize()
{
	
}

// 更新処理
void Gage::Update()
{
	// 入力情報取得
	int Key = GetJoypadInputState(DX_INPUT_PAD1);

	// Aボタンが押されたら値を変動しないようにする
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		decision = true;
	}

	if (PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
	{
		decision = false;
	}

	// デバッグ用
	if (Key & PAD_INPUT_B)
	{
		decision = false;
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
	// ゲージの後ろの黒い四角
	//DrawBox(280, 650, 200, 120, GetColor(0, 0, 0), true);
	DrawBox(30, 50, 630, 100, GetColor(0, 0, 0), true);


	// ゲージの枠線
	//DrawBox(280, 650, 200, 120, GetColor(255, 0, 0), false);
	DrawBox(30, 50, 630, 100, GetColor(255, 0, 0), false);

	// ゲージの動く部分を描画
	//DrawBox(280, 650, 200, 650 - (530 * (0.01 * meter)), GetColor(255, 0, 0), true);
	DrawBox(30, 50, 30 + (600 * (0.01 * meter)), 100, GetColor(255, 0, 0), true);
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

int Gage::GetMeter()
{
	return meter;
}
