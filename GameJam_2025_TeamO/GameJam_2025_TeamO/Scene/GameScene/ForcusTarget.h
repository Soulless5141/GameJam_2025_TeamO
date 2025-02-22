#pragma once
#include "../SceneManager.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "../../Objects/Player/Player.h"

class ForcusTarget
{
public:
	Player* player;

	int background;

private:
	int SelectFlg;

public:
	ForcusTarget();
	~ForcusTarget();

	void ForcusSceneInit(void);
	eSceneType ForcusSceneUpdate();
	void ForcusSceneDraw(void);

};
