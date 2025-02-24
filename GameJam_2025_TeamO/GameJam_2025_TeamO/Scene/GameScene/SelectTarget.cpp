#include "SelectTarget.h"
#include "../../Objects/Mato/Mato.h"

SelectTarget::SelectTarget()
{
	ForcusFlg = FALSE;
	background = LoadGraph("background.png");  // 画像のパスを指定
	
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
	CreateObject<Mato>(Vector2D(100, 100));
}

eSceneType SelectTarget::Update(const float& delta_second)
{
	SceneBase::Update(delta_second);
	//mato->Update();
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
	SceneBase::Draw();
	DrawFormatString(0, 0, 0xffffff, "select scene");
	DrawGraph(0, 0, background, TRUE);

	// 的の仮描画
	DrawBox(100, 100, 200, 200, 0xffffff, TRUE);
	DrawBox(250, 100, 350, 200, 0xffffff, TRUE);
	DrawBox(400, 100, 500, 200, 0xffffff, TRUE);

	DrawBox(100, 250, 200, 350, 0xffffff, TRUE);
	DrawBox(250, 250, 350, 350, 0xffffff, TRUE);
	DrawBox(400, 250, 500, 350, 0xffffff, TRUE);
}

const eSceneType SelectTarget::GetNowSceneType() const
{
	return eSceneType::eSelectMode;
}
