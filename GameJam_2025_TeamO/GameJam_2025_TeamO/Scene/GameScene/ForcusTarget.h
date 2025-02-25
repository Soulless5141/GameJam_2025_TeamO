#pragma once
#include "../SceneManager.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "../../Objects/Player/Player.h"
#include "../../Objects/Mato/Mato.h"
#include "../../Objects/Gage/Gage.h"
#include "../../Objects/RemainingBullets/RemainingBullets.h"

class ForcusTarget : public SceneBase
{
public:
	Player* player;
	Gage* gage;
	RemainingBullets* bullet;

	int background;

private:
	int SelectFlg;

public:
	ForcusTarget();
	~ForcusTarget();

	void ForcusSceneInit(void);
	eSceneType ForcusSceneUpdate();
	void ForcusSceneDraw(void);

	virtual const eSceneType GetNowSceneType() const override;
};
