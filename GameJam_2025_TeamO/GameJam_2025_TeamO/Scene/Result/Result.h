#pragma once

#include "../SceneBase.h"


//void ResultSceneInit(void);
//eSceneType ResultSceneUpdate();
//void ResultSceneDraw(void);

class Result : public SceneBase
{
private:

	int back_ground;      //�w�i�摜
	int num_img[10];          //�����摜
	int score;            //�X�R�A
	int r_score;
	int mileage;		  //���s����
	int enemy_count[3];   //�G�̃J�E���g
	int enemy_image[3];   //�G�摜

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