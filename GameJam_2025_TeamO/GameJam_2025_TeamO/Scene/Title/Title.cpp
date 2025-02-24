#include "Title.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int title_background_image;  //�w�i�ݒ�p�̕ϐ�
int title_bgm;               //BGM�ݒ�p�̕ϐ�
int cursor_number;

//�^�C�g����ʂ̏�����
void TitleSceneInit(void)
{
	cursor_number = eStart_Title;
}

//�^�C�g����ʂ̃A�b�v�f�[�g
eSceneType TitleSceneUpdate()
{
	int key_title = GetJoypadInputState(DX_INPUT_PAD1);

	//�I��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		if (cursor_number == eStart_Title)
		{
			return eSelectMode;
		}
		else if (cursor_number == eHelp_Title)
		{
			return eHelp;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		cursor_number++;

		if (cursor_number > 1)
		{
			cursor_number = eStart_Title;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		cursor_number--;

		if (cursor_number < 0)
		{
			cursor_number = eHelp_Title;
		}
	}

	return eTitle;
}

//�^�C�g����ʂ̕`��
void TitleSceneDraw(void)
{
	/*�`�悷�镶��*/
	SetFontSize(30);
	DrawFormatString(500,470,GetColor(255,255,255), "�X�^�[�g");
	DrawFormatString(500,500, GetColor(255, 255, 255),"�w���v");
	DrawFormatString(500,530, GetColor(255, 255, 255),"�����L���O");
	DrawFormatString(500,560, GetColor(255, 255, 255),"�G���h");
	DrawCircle(450, 480 + cursor_number * 30, 15, GetColor(255, 255, 255), TRUE);
}