#include "SelectTarget.h"
#include "../../Objects/Mato/Mato.h"

SelectTarget::SelectTarget()
{
	ForcusFlg = FALSE;
	background = LoadGraph("Resource/Images/BGI.jpg");  // 画像のパスを指定
	
}

SelectTarget::~SelectTarget()
{
	DeleteGraph(background);
}

//void SelectSceneInit()
//{
//}

void SelectTarget::Initialize()
{
	//的の描画
	CreateObject<Mato>(Vector2D(300, 300));
	CreateObject<Mato>(Vector2D(300, 550));
	CreateObject<Mato>(Vector2D(550, 300));
	CreateObject<Mato>(Vector2D(550, 550));
	//CreateObject<Mato>(Vector2D(800, 300));
	//CreateObject<Mato>(Vector2D(800, 550));
	//CreateObject<Mato>(Vector2D(900, 300));
	//CreateObject<Mato>(Vector2D(900, 550));
}

eSceneType SelectTarget::Update(const float& delta_second)
{
	//mato->Update(delta_second);
	SceneBase::Update(delta_second);
	
	//選択した的からシーン遷移
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
	//背景画像の描画
	DrawRotaGraph(640, 375, 0.6, 0.0, background, TRUE);

	// 的の仮描画
	SceneBase::Draw();
}

const eSceneType SelectTarget::GetNowSceneType() const
{
	return eSceneType::eSelectMode;
}
