#include "HelpScene.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

//int help_background_image;  //�w�i�ݒ�p�̕ϐ�
//int help_bgm;               //BGM�ݒ�p�̕ϐ�

int help_scope;
int help_nuigurumi;
int help_bullet;
int help_img;

//�w���v��ʂ̏�����
void HelpSceneInit(void)
{
	help_scope = LoadGraph("Resource/Images/scope.png");
	help_nuigurumi = LoadGraph("Resource/Images/keihin1.png");
	help_bullet = LoadGraph("Resource/Images/bullet.png");
	help_img = LoadGraph("Resource/Images/Help.jpg");
}

//�w���v��ʂ̃A�b�v�f�[�g
eSceneType HelpSceneUpdate(void)
{
	int key_help = GetJoypadInputState(DX_INPUT_PAD1);

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return eTitle;
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT))
	{
		return eHelp2;
	}

	return eHelp;
}

//�w���v��ʂ̕`��
void HelpSceneDraw(void)
{
	DrawFormatString(50, 50, GetColor(255, 255, 255), "�w���v���");
	DrawFormatString(900, 600, GetColor(255, 255, 255), "B�F�߂�");
	DrawFormatString(640, 600, GetColor(255, 255, 255), "1�@��");

	DrawRotaGraph(0, 0, 1.0, 0, help_img, 0, 0);
}