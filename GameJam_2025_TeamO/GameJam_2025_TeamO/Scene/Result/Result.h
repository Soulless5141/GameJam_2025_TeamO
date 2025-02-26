#pragma once

#include "../SceneBase.h"


//void ResultSceneInit(void);
//eSceneType ResultSceneUpdate();
//void ResultSceneDraw(void);

class Result : public SceneBase
{
private:

	int back_ground;      //背景画像
	int num_img[10];          //数字画像
	int score;            //スコア
	int r_score;
	int mileage;		  //走行距離
	int enemy_count[3];   //敵のカウント
	int enemy_image[3];   //敵画像

public:
	Result();
	virtual ~Result();

	virtual void Initialize() override;
	virtual eSceneType Update(const float& delta_second) override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual const eSceneType GetNowSceneType() const override;

private:
	void ReadResultData();
	void ReadRankingData();
};