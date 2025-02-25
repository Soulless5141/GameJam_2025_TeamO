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
	Mato* m = CreateObject<Mato>(Vector2D(300, 320));
	CreateObject<Mato>(Vector2D(300, 550));
	CreateObject<Mato>(Vector2D(530, 320));
	CreateObject<Mato>(Vector2D(530, 550));
	CreateObject<Mato>(Vector2D(750, 320));
	CreateObject<Mato>(Vector2D(750, 550));
	CreateObject<Mato>(Vector2D(980, 320));
	CreateObject<Mato>(Vector2D(980, 550));
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
	//
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
