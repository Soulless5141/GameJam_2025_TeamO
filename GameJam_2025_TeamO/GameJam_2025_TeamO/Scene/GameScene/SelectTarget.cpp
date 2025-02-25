#include "SelectTarget.h"
#include "../../Objects/Mato/Mato.h"

SelectTarget::SelectTarget()
{
	gage = new Gage;
	bullet = new RemainingBullets;

	SelectFlg = FALSE;
	ForcusFlg = FALSE;
	background = LoadGraph("Resource/Images/BGI.jpg");  // ‰æ‘œ‚ÌƒpƒX‚ðŽw’è
	
	for (int i = 0; i < 8; i++)
	{
		mato[i] = nullptr;
	}

}

SelectTarget::~SelectTarget()
{
	
	delete gage;
	delete bullet;
	
	DeleteGraph(background);
}

//void SelectSceneInit()
//{
//}

void SelectTarget::Initialize()
{
	Vector2D positions[8] =
	{
		{300,320},{300,550},{530,320},{530, 550},
		{750, 320},{750, 550},{980, 320},{980,550}
	};

	for (int i = 0; i < 8; i++)
	{
		mato[i] = CreateObject<Mato>(positions[i]);
	}

	//“I‚Ì•`‰æ
	//CreateObject<Mato>(Vector2D(300, 320));
	//CreateObject<Mato>(Vector2D(300, 550));
	//CreateObject<Mato>(Vector2D(530, 320));
	//CreateObject<Mato>(Vector2D(530, 550));
	//CreateObject<Mato>(Vector2D(750, 320));
	//CreateObject<Mato>(Vector2D(750, 550));
	//CreateObject<Mato>(Vector2D(980, 320));
	//CreateObject<Mato>(Vector2D(980, 550));

	player = CreateObject<Player>(Vector2D(570, 320));
}

//eSceneType SelectTarget::SelectSceneUpdate()
//{
//	player->Update();
//
//	//‘I‘ð‚µ‚½“I‚©‚çƒV[ƒ“‘JˆÚ
//	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
//	{
//		return eForcusMode;
//	}
//
//	return eSelectMode;
//}

eSceneType SelectTarget::Update(const float& delta_second)
{
	gage->Update();
	bullet->Update();
	SceneBase::Update(delta_second);

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) && SelectFlg == FALSE)
	{
		SelectFlg = TRUE;
	}


	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{

		for (int i = 0; i < 8; i++)
		{
			if (IsHitCheck(player, mato[i]) == true)
			{
				damage *= gage->GetMeter();
				mato[i]->GetHp();
				mato[i]->DecreaseHp(damage);
				if (mato[i]->hp==0)
				{
					mato[i]->Finalize();
					score += 10;
				}
				
				
			}
		};
	}

	if (PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
	{
		damage = 1;
	}
		
	

	//’e‚ðŒ‚‚Á‚ÄŠO‚µ‚½‚çŽc’e‚ðŒ¸ŽZ‚µ‚ÄƒV[ƒ“‘JˆÚ
	if (SelectFlg == TRUE)
	{
		SelectFlg = FALSE;
		bullet->LifeReduce();
		//return eForcusMode;
	}

	////Žc’e‚ª‚È‚­‚È‚Á‚½‚çƒŠƒUƒ‹ƒg‚É‘JˆÚ
	//if (bullet->GetLife() <= 0)
	//{
	//	return eResult;
	//}

	old_location = player->GetLocation();

	return eSelectMode;
}

//void SelectTarget::SelectSceneDraw(void)
//{
//	player->Draw();
//	DrawFormatString(0, 0, 0xffffff, "select scene");
//	DrawGraph(0, 0, background, TRUE);
//}

void SelectTarget::Draw() const
{

	//”wŒi‰æ‘œ‚Ì•`‰æ
	DrawRotaGraph(640, 375, 1.0, 0.0, background, TRUE);

	// “I‚Ì‰¼•`‰æ
	SceneBase::Draw();

	//player->Draw();
	
	DrawFormatString(0, 0, 0xffffff, "%d\n", score);
	DrawFormatString(10, 50, 0xffffff, "%d\n", gage->GetMeter());
	SetFontSize(48);
	DrawFormatString(100, 100, 0xffffff, "%d\n", player->GivesDamage());
	DrawFormatString(200, 200, 0xff0000, "%d\n", damage);

	gage->Draw();
	bullet->Draw();
}

bool SelectTarget::IsHitCheck(Player* p, Mato* m)
{
	Vector2D playerPos = p->GetLocation();
	Vector2D matoPos = m->GetLocation();
	Vector2D playerSize = p->GetboxSize();
	Vector2D matoSize = m->GetboxSize();

	Vector2D box_ex = playerSize + matoSize;

	if (fabs(playerPos.x - matoPos.x) < box_ex.x / 2 &&
		fabs(playerPos.y - matoPos.y) < box_ex.y / 2)
	{
		return true;
	}

		return false;
}

const eSceneType SelectTarget::GetNowSceneType() const
{
	return eSceneType::eSelectMode;
}
