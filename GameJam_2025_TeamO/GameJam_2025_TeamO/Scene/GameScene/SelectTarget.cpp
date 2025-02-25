#include "SelectTarget.h"
#include "../../Objects/Mato/Mato.h"

SelectTarget::SelectTarget()
{
	player = new Player;
	gage = new Gage;
	bullet = new RemainingBullets;
	SelectFlg = FALSE;
	ForcusFlg = FALSE;
	background = LoadGraph("Resource/Images/BGI.jpg");  // ‰æ‘œ‚ÌƒpƒX‚ðŽw’è
	
}

SelectTarget::~SelectTarget()
{
	delete player;
	delete gage;
	delete bullet;
	DeleteGraph(background);
}

//void SelectSceneInit()
//{
//}

void SelectTarget::Initialize()
{
	//“I‚Ì•`‰æ
	Mato* m = CreateObject<Mato>(Vector2D(300, 300));
	CreateObject<Mato>(Vector2D(300, 550));
	CreateObject<Mato>(Vector2D(550, 300));
	CreateObject<Mato>(Vector2D(550, 550));
	//CreateObject<Mato>(Vector2D(800, 300));
	//CreateObject<Mato>(Vector2D(800, 550));
	//CreateObject<Mato>(Vector2D(900, 300));
	//CreateObject<Mato>(Vector2D(900, 550));
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
	//mato->Update(delta_second);
	gage->Update();
	bullet->Update();
	SceneBase::Update(delta_second);

	//if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) && SelectFlg == FALSE)
	//{
	//	SelectFlg = TRUE;
	//}

	////’e‚ðŒ‚‚Á‚ÄŠO‚µ‚½‚çŽc’e‚ðŒ¸ŽZ‚µ‚ÄƒV[ƒ“‘JˆÚ
	//if (SelectFlg == TRUE)
	//{
	//	SelectFlg = FALSE;
	//	bullet->LifeReduce();
	//	return eForcusMode;
	//}

	////Žc’e‚ª‚È‚­‚È‚Á‚½‚çƒŠƒUƒ‹ƒg‚É‘JˆÚ
	//if (bullet->GetLife() <= 0)
	//{
	//	return eResult;
	//}

	
	//‘I‘ð‚µ‚½“I‚©‚çƒV[ƒ“‘JˆÚ
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return eForcusMode;
	}

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
	DrawRotaGraph(640, 375, 0.6, 0.0, background, TRUE);

	// “I‚Ì‰¼•`‰æ
	SceneBase::Draw();

	gage->Draw();
	bullet->Draw();
}

const eSceneType SelectTarget::GetNowSceneType() const
{
	return eSceneType::eSelectMode;
}
