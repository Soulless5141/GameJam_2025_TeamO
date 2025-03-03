#pragma once
#include "../../Utility/ResourceManager.h"
#include <string>

class RemainingBullets
{
private:
	int life_bullet; // 残弾
	std::vector<int> image;

public:
	RemainingBullets();
	~RemainingBullets();

	void Initialize();	// 初期化処理
	void Update();		// 更新処理
	void Draw();		// 描画処理
	void Finalize();	// 終了処理

	int GetLife();		// 残弾数取得処理
	void LifeReduce();	// 残弾の減少処理

};

