#include "SelectTarget.h"
#include "../../Objects/Mato/Mato.h"

SelectTarget::SelectTarget()
{
	player = new Player;
	ForcusFlg = FALSE;
	background = LoadGraph("Resource/Images/BGI.jpg");  // ‰æ‘œ‚ÌƒpƒX‚ðŽw’è
	
}

SelectTarget::~SelectTarget()
{
	delete player;
	DeleteGraph(background);
}

//void SelectSceneInit()
//{
//}

void SelectTarget::Initialize()
{
	//“I‚Ì•`‰æ
	CreateObject<Mato>(Vector2D(300, 300));
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
	SceneBase::Update(delta_second);
	
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
}

const eSceneType SelectTarget::GetNowSceneType() const
{
	return eSceneType::eSelectMode;
}
