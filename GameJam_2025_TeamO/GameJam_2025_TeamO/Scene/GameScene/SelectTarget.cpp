#include "SelectTarget.h"

SelectTarget::SelectTarget()
{
	player = new Player;
	ForcusFlg = FALSE;
	background = LoadGraph("background.png");  // 画像のパスを指定
	
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
	//選択した的からシーン遷移
	if (ForcusFlg == TRUE)
	{

	}
}

void SelectTarget::SelectSceneDraw(void)
{
	DrawGraph(0, 0, background, TRUE);
}