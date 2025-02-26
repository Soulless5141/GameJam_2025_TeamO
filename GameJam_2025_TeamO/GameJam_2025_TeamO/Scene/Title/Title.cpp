#include "Title.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int title_background_image;  //�w�i�ݒ�p�̕ϐ�
int sentaku_img;                 //���艹
int idou_bgm;                    //�ړ���
int kettei_bgm;                  //���艹
int title_bgm;               //BGM�ݒ�p�̕ϐ�
int cursor_number = eStart_Title;

//�^�C�g����ʂ̏�����
void TitleSceneInit(void)
{
	title_background_image = LoadGraph("Resource/Images/Title.jpg");
	sentaku_img = LoadGraph("Resource/Images/bullet.png");
	kettei_bgm = LoadSoundMem("Resource/Sounds/����{�^��������3.mp3");
	idou_bgm = LoadSoundMem("Resource/Sounds/�J�[�\���ړ�5.mp3");
	title_bgm = LoadSoundMem("Resource/Sounds/yomatsuri.mp3");

	PlaySoundMem(title_bgm, DX_PLAYTYPE_LOOP, TRUE);
}

//�^�C�g����ʂ̃A�b�v�f�[�g
eSceneType TitleSceneUpdate()
{
	int key_title = GetJoypadInputState(DX_INPUT_PAD1);

	//�I��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		PlaySoundMem(kettei_bgm, DX_PLAYTYPE_BACK,TRUE); //�����̍Đ�

		//�V�[���̐؂�ւ�
		if (cursor_number == eStart_Title)
		{
			DeleteSoundMem(title_bgm);
			return eSelectMode;
		}
		else if (cursor_number == eHelp_Title)
		{
			DeleteSoundMem(title_bgm);
			return eHelp;
		}
		else if (cursor_number == eRanking_title)
		{
			DeleteSoundMem(title_bgm);
			return eRanking_Scene;
		}
		else if (cursor_number == eEnd_title)
		{
			DeleteSoundMem(title_bgm);
			return eEnd;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		//�����̍Đ�
		//PlaySoundMem(title_bgm, DX_PLAYTYPE_NORMAL, TRUE);
		PlaySoundMem(idou_bgm, DX_PLAYTYPE_BACK, TRUE);

		cursor_number++;

		if (cursor_number > 3)
		{
			cursor_number = eStart_Title;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		PlaySoundMem(idou_bgm, DX_PLAYTYPE_BACK, TRUE);
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

	DrawRotaGraph(530, 515 + cursor_number * 31, 0.1, 12.55, sentaku_img, TRUE, TRUE);
	//DrawCircle(550, 510 + cursor_number * 30, 15, GetColor(0, 0, 0), TRUE);
}