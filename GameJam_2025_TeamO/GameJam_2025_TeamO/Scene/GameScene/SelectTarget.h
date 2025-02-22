#pragma once
#include "../SceneManager.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "../../Objects/Player/Player.h"

class SelectTarget : public SceneType
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

	void SelectSceneInit(void);
	eSceneType SelectSceneUpdate();
	void SelectSceneDraw(void);
	
	virtual eSceneType GetNowScene() const override;
};
