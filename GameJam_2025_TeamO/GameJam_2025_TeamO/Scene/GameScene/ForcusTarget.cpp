#include "ForcusTarget.h"

ForcusTarget::ForcusTarget()
{
	player = new Player;
	SelectFlg = FALSE;
	background = LoadGraph("background.png");  // �摜�̃p�X���w��

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

	//�e�������ĊO������c�e�����Z���ăV�[���J��
	/*if ( == TRUE)
	{
		return eForcusMode;
	}*/

	//�e�������ē���������c�e�����Z���ăX�R�A���Z���ăV�[���J��
	/*if (== TRUE)
	{
		return eSelectMode;
	}*/

	//�c�e���Ȃ��Ȃ����烊�U���g�ɑJ��
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

const eSceneType ForcusTarget::GetNowSceneType() const
{
	return eSceneType::eForcusMode;
}
//const eSceneType GetNowSceneType()
//{
//	return eSceneType::eForcusMode;
//}