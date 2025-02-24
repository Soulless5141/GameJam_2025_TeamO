#include "SelectTarget.h"

SelectTarget::SelectTarget()
{
	player = new Player;
	ForcusFlg = FALSE;
	background = LoadGraph("background.png");  // �摜�̃p�X���w��
	
}

SelectTarget::~SelectTarget()
{
	delete player;
	DeleteGraph(background);
}

void SelectSceneInit()
{
}

eSceneType SelectTarget::SelectSceneUpdate()
{
	player->Update();

	//�I�������I����V�[���J��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return eForcusMode;
	}

	return eSelectMode;
}

void SelectTarget::SelectSceneDraw(void)
{
	player->Draw();
	DrawFormatString(0, 0, 0xffffff, "select scene");
	DrawGraph(0, 0, background, TRUE);

	// �I�̉��`��
	DrawBox(100, 100, 200, 200, 0xffffff, TRUE);
	DrawBox(250, 100, 350, 200, 0xffffff, TRUE);
	DrawBox(400, 100, 500, 200, 0xffffff, TRUE);

	DrawBox(100, 250, 200, 350, 0xffffff, TRUE);
	DrawBox(250, 250, 350, 350, 0xffffff, TRUE);
	DrawBox(400, 250, 500, 350, 0xffffff, TRUE);
}

eSceneType SelectTarget::GetNowScene() const
{
	return eSceneType::eSelectMode;
}