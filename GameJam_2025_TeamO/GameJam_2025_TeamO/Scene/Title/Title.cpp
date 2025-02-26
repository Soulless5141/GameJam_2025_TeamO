#include "Title.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int title_background_image;  //�w�i�ݒ�p�̕ϐ�
int title_name;              //�Q�[����
int title_bgm;               //BGM�ݒ�p�̕ϐ�
int cursor_number = eStart_Title;

//�^�C�g����ʂ̏�����
void TitleSceneInit(void)
{
	title_background_image = LoadGraph("Resource/Images/Title.jpg");

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
		else if (cursor_number == eRanking_title)
		{
			return eRanking_Scene;
		}
		else if (cursor_number == eEnd_title)
		{
			return eEnd;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		cursor_number++;

		if (cursor_number > 3)
		{
			cursor_number = eStart_Title;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		cursor_number--;

		if (cursor_number < 0)
		{
			cursor_number = eEnd_title;
		}
	}

	return eTitle;
}

//�^�C�g����ʂ̕`��
void TitleSceneDraw(void)
{
	/*�`�悷��摜*/
	DrawRotaGraph(640, 360, 0.77, 0, title_background_image, 0, 0);

	/*�`�悷�镶��*/
	SetFontSize(30);
	DrawFormatString(580,500,GetColor(0,0,0), "�X�^�[�g");
	DrawFormatString(580,530, GetColor(0, 0, 0),"�w���v");
	DrawFormatString(580,560, GetColor(0, 0, 0),"�����L���O");
	DrawFormatString(580,590, GetColor(0, 0, 0),"�G���h");
	DrawCircle(550, 510 + cursor_number * 30, 15, GetColor(0, 0, 0), TRUE);
}