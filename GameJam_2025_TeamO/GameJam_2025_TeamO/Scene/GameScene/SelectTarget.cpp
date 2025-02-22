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
	if (ForcusFlg == TRUE)
	{
		return eForcusMode;
	}

	return eSelectMode;
}

void SelectTarget::SelectSceneDraw(void)
{
	player->Draw();
	DrawGraph(0, 0, background, TRUE);
}

eSceneType SelectTarget::GetNowScene() const
{
	return eSceneType::eSelectMode;
}