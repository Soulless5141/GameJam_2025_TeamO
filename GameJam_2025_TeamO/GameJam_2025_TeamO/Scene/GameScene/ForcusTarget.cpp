#include "ForcusTarget.h"

ForcusTarget::ForcusTarget()
{
	player = new Player;
	gage = new Gage;
	SelectFlg = FALSE;
	background = LoadGraph("background.png");  // ‰æ‘œ‚ÌƒpƒX‚ðŽw’è

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
	gage->Update();

	//’e‚ðŒ‚‚Á‚ÄŠO‚µ‚½‚çŽc’e‚ðŒ¸ŽZ‚µ‚ÄƒV[ƒ“‘JˆÚ
	/*if ( == TRUE)
	{
		return eForcusMode;
	}*/

	//’e‚ðŒ‚‚Á‚Ä“–‚½‚Á‚½‚çŽc’e‚ðŒ¸ŽZ‚µ‚ÄƒXƒRƒA‰ÁŽZ‚µ‚ÄƒV[ƒ“‘JˆÚ
	/*if (== TRUE)
	{
		return eSelectMode;
	}*/

	//Žc’e‚ª‚È‚­‚È‚Á‚½‚çƒŠƒUƒ‹ƒg‚É‘JˆÚ
	/*if (== TRUE)
	{
		return eResult;
	}*/
		
	return eForcusMode;
}

void ForcusTarget::ForcusSceneDraw(void)
{
	player->Draw();
	gage->Draw();
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