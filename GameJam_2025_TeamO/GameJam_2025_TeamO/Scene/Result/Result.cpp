#include "Result.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int result_background_image;  //�w�i�ݒ�p�̕ϐ�
int result_bgm;               //BGM�ݒ�p�̕ϐ�

void ResultSceneInit(void)
{

}

eSceneType ResuleUpdate(void)
{
	return eResult;
}

void ResultSceneDraw(void)
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "���U���g���");
}