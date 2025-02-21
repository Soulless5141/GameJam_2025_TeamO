#pragma once
#include"DxLib.h"

#define BUTTONS 16

// スティック
struct Stick
{
	short ThumbX;	// X軸の値
	short ThumbY;	// Y軸の値
};

class PAD_INPUT
{
private:
	static char NowKey[BUTTONS]; // 現在の入力キー
	static char OldKey[BUTTONS]; // 前回の入力キー
	static XINPUT_STATE Input; // パッドの状態
	static Stick Rstick; // 右スティック
	static Stick Lstick; // 左スティック
private:
	// コンストラクタ
	PAD_INPUT() = default;
public:
	// パッド入力の更新
	static void UpdateKey()
	{
		// 入力キー取得
		GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
		for (int i = 0; i < BUTTONS; i++)
		{
			OldKey[i] = NowKey[i];
			NowKey[i] = Input.Buttons[i];
		}

		// 右スティック
		Rstick.ThumbX = Input.ThumbRX;
		Rstick.ThumbY = Input.ThumbRY;

		// 左スティック
		Lstick.ThumbX = Input.ThumbLX;
		Lstick.ThumbY = Input.ThumbLY;
	}

	// ボタンが押された瞬間
	static bool OnButton(int button)
	{
		bool ret = (NowKey[button] == 1 && OldKey[button] == 0);
		return ret;
	}

	// ボタンが離された瞬間
	static bool OnRelease(int button)
	{
		bool ret = (NowKey[button] == 0 && OldKey[button] == 1);
		return ret;
	}

	// 右スティックの取得
	static Stick GetRStick()
	{
		return Rstick;
	}

	// 左スティックの取得
	static Stick GetLStick()
	{
		return Lstick;
	}
};

