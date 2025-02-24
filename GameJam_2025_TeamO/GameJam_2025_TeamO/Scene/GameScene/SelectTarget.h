#pragma once
#include "../SceneManager.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "../../Objects/Mato/Mato.h"
#include "../../Objects/Player/Player.h"
#include "../../Objects/RemainingBullets/RemainingBullets.h"
#include"../SceneBase.h"

class SelectTarget : public SceneBase
{
public:
	Player* player;
	RemainingBullets* bullet;
	Mato* mato;

	int background;
	int score;
	
private:
	int ForcusFlg;

public:
	SelectTarget();
	~SelectTarget();

	//void SelectSceneInit(void);
	virtual void Initialize();
	virtual eSceneType Update(const float& delta_second) override;
	virtual void Draw() const override;

	virtual const eSceneType GetNowSceneType() const override;
};
