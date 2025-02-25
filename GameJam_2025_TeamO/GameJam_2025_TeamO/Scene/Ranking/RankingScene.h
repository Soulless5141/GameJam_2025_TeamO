#pragma once

#include "../SceneBase.h"
#include"RankingData.h"

class RankingScene : public SceneBase
{
private:

private:
	int background_image;  //”wŒi‰æ‘œ
	RankingData* ranking;  //ƒ‰ƒ“ƒLƒ“ƒOî•ñ

public:
	RankingScene();
	virtual ~RankingScene();

	virtual void Initialize() override;
	virtual eSceneType Update(const float& delta_second);
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual const eSceneType GetNowSceneType() const override;
};