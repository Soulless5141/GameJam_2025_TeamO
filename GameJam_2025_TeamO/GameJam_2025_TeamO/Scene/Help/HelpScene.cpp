#include "HelpScene.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int help_background_image;  //�w�i�ݒ�p�̕ϐ�
int help_bgm;               //BGM�ݒ�p�̕ϐ�

//�w���v��ʂ̏�����
void HelpSceneInit(void)
{

}

//�w���v��ʂ̃A�b�v�f�[�g
eSceneType HelpSceneUpdate(void)
{
	return eHelp;
}

//�w���v��ʂ̕`��
void HelpSceneDraw(void)
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "�w���v���");
}