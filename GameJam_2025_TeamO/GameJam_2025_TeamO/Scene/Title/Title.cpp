#include "Title.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int title_background_image;  //�w�i�ݒ�p�̕ϐ�
int title_bgm;               //BGM�ݒ�p�̕ϐ�

//�^�C�g����ʂ̏�����
void TitleSceneInit(void)
{

}

//�^�C�g����ʂ̃A�b�v�f�[�g
eSceneType TitleSceneUpdate()
{
	int key_title = GetJoypadInputState(DX_INPUT_PAD1);

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return eHelp;
	}

	return eTitle;
}

//�^�C�g����ʂ̕`��
void TitleSceneDraw(void)
{
	/*�`�悷�镶��*/
	SetFontSize(30);
	DrawFormatString(100,500,GetColor(255,255,255), "�X�^�[�g");
	DrawFormatString(500,500, GetColor(255, 255, 255),"�w���v");
}