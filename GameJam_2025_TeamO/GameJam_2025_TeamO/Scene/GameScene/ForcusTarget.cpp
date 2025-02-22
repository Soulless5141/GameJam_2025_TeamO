#include "ForcusTarget.h"

ForcusTarget::ForcusTarget()
{
	player = new Player;
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
	}*/
		return eResult;
	
}

void ForcusTarget::ForcusSceneDraw(void)
{
	player->Draw();

	DrawGraph(0, 0, background, TRUE);
}

eSceneType ForcusTarget::GetNowScene() const
{
	return eSceneType::eForcusMode;
}