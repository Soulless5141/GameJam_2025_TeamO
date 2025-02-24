#pragma once
#include "../SceneManager.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "../../Objects/Player/Player.h"
#include"../SceneBase.h"

class SelectTarget : public SceneBase
{
public:
	Player* player;

	int background;
	int score;
	
private:
	int ForcusFlg;

public:
	SelectTarget();
	~SelectTarget();

	//void SelectSceneInit(void);
	virtual void Initialize();
	eSceneType SelectSceneUpdate();
	//virtual eSceneType Update(const float& delta_second);
	//void SelectSceneDraw(void);
	virtual void Draw() const;

	virtual const eSceneType GetNowSceneType() const override;
};
