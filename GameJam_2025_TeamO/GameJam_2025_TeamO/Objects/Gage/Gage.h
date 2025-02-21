#pragma once
#include "../../Utility/PadInput.h"

class Gage
{
private:
	int meter;				// ゲージの中身
	int fluctuation;        // ゲージの変動値
	bool change_flip_flag;  // ゲージが増えてるか減っているのか
	bool decision;			// Aボタンが押されたか

public:
	Gage();
	~Gage();

	void Initialize();	// 初期化処理
	void Update();		// 更新処理
	void Draw();		// 描画処理
	void Finalize();	// 終了処理

	void ChangeMove();	// ゲージの値の変動処理
};

