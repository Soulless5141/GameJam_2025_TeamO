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
	//�I�������I����V�[���J��
	if (ForcusFlg == TRUE)
	{

	}
}

void SelectTarget::SelectSceneDraw(void)
{
	DrawGraph(0, 0, background, TRUE);
}