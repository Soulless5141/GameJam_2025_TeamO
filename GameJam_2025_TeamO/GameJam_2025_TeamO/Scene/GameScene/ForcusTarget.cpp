#include "ForcusTarget.h"

ForcusTarget::ForcusTarget()
{
	player = new Player;
	SelectFlg = FALSE;
	background = LoadGraph("background.png");  // 画像のパスを指定

}

ForcusTarget::~ForcusTarget()
{
	delete player;
	DeleteGraph(background);
}

void ForcusSceneInit()
{
}

eSceneType ForcusTarget::ForcusSceneUpdate()
{
	player->Update();

	//弾を撃って外したら残弾を減算してシーン遷移
	/*if ( == TRUE)
	{
		return eForcusMode;
	}*/

	//弾を撃って当たったら残弾を減算してスコア加算してシーン遷移
	/*if (== TRUE)
	{
		return eSelectMode;
	}*/

	//残弾がなくなったらリザルトに遷移
	/*if (== TRUE)
	{
		return eResult;
	}*/
		
	return eForcusMode;
}

void ForcusTarget::ForcusSceneDraw(void)
{
	player->Draw();
	DrawFormatString(0, 0, 0xffffff, "forcus scene");
	DrawGraph(0, 0, background, TRUE);
}

eSceneType ForcusTarget::GetNowScene() const
{
	return eSceneType::eForcusMode;
}