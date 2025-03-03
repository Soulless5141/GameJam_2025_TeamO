#include "ForcusTarget.h"

ForcusTarget::ForcusTarget()
{
	player = new Player;
	gage = new Gage;
	bullet = new RemainingBullets;
	SelectFlg = FALSE;
	background = LoadGraph("background.png");  // 画像のパスを指定

}

ForcusTarget::~ForcusTarget()
{
	delete player;
	delete gage;
	delete bullet;
	DeleteGraph(background);
}

void ForcusSceneInit()
{
}

eSceneType ForcusTarget::ForcusSceneUpdate()
{
	//player->Update();
	gage->Update();
	bullet->Update();

	if (XINPUT_BUTTON_A && SelectFlg == FALSE)
	{
		SelectFlg = TRUE;
	}

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
	if (bullet->GetLife() <= 0)
	{
		return eResult;
	}
		
	return eForcusMode;
}

void ForcusTarget::ForcusSceneDraw(void)
{
	//player->Draw();
	gage->Draw();
	bullet->Draw();
	DrawFormatString(0, 0, 0xffffff, "forcus scene");
	DrawGraph(0, 0, background, TRUE);
}

const eSceneType ForcusTarget::GetNowSceneType() const
{
	return eSceneType::eForcusMode;
}
//const eSceneType GetNowSceneType()
//{
//	return eSceneType::eForcusMode;
//}
//
//bool ForcusTarget::IsHitCheck(Player* p, Mato* m)
//{
//	return 0;
//}