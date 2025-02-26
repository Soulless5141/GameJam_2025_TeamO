#include "RankingInput.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

RankingInputScene::RankingInputScene() : background_image(NULL),
ranking(nullptr), score(10), name_num(0), cursor_x(0), cursor_y(0),
rankinginput_bgm(NULL), select_se(NULL), decision_se(NULL)
{
	memset(name, NULL, (sizeof(char) * 15));
}

RankingInputScene::~RankingInputScene()
{

}

//����������
void RankingInputScene::Initialize()
{
	//�������̓��I�m��
	ranking = new RankingData;
	ranking->Initialize();

	background_image = LoadGraph("Resource/images/BGI.jpg");


	//���U���g�f�[�^���擾����
	FILE* fp = nullptr;
	//�t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/Data/result.csv", "r");

	//�G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/Data/result.csv���ǂݍ��߂܂���\n");
	}

	//���ʂ�ǂݍ���
	fscanf_s(fp, "%6d,\n", &score);

	//�t�@�C���N���[�Y
	fclose(fp);
}

//�X�V����
eSceneType RankingInputScene::Update()
{
	bool is_change = false;

	//BGM�Đ�
	//PlaySoundMem(rankinginput_bgm, DX_PLAYTYPE_LOOP, FALSE);

	//���O���͏���
	is_change = InputName();

	//�V�[���ύX�͉\���H
	if (is_change)
	{
		//�����L���O�\���ɑJ��
		return eSceneType::eRanking_Scene;
	}
	else
	{
		return GetNowSceneType();
	}
}

//�`�揈��
void RankingInputScene::Draw() const
{
	//�w�i�摜�̕`��
	DrawGraph(0, 0, background_image, TRUE);
	DrawBox(220, 200, 1000, 700, GetColor(255, 255, 255), true);

	//���O���͎w��������
	SetFontSize(60);
	DrawString(120, 70, "�����L���O�o�^", 0x000000);

	SetFontSize(32);
	DrawFormatString(400, 220, GetColor(0, 0, 0), ">%s", name);

	//�I�𕶎���`��
	const int font_size = 50;
	for (int i = 0; i < 26; i++)
	{
		int x = (i % 13) * font_size + 315;
		int y = (i / 13) * font_size + 300;
		DrawFormatString(x, y, GetColor(0, 0, 0), "%-3c", 'a' + i);
		y = ((i / 13) + 2) * font_size + 300;
		DrawFormatString(x, y, GetColor(0, 0, 0), "%-3c", 'A' + i);
	}
	DrawString(440, 605, "����", GetColor(0, 0, 0));
	DrawString(640 + font_size * 2, 605, "����", GetColor(0, 0, 0));

	//�I�𕶎����t�H�[�J�X����
	if (cursor_y < 4)
	{
		int x = cursor_x * font_size + 300;
		int y = cursor_y * font_size + 295;
		DrawBox(x, y, x + font_size, y + font_size, GetColor(0, 0, 0), FALSE);
	}
	else
	{
		if (cursor_x == 0)
		{
			DrawBox(435, 600, 420 + font_size * 2, 600 + font_size, GetColor(0, 0, 0), FALSE);
		}
		else
		{
			DrawBox(725, 600, 725 + font_size * 2, 600 + font_size, GetColor(0, 0, 0), FALSE);
		}
	}
}

//�I��������
void RankingInputScene::Finalize()
{
	//�����L���O�Ƀf�[�^���i�[
	ranking->SetRankingData(score, name);

	//�ǂݍ��񂾉摜���폜
	DeleteGraph(background_image);

	//�ǂݍ���BGM�̍폜
	DeleteSoundMem(rankinginput_bgm);

	//�ǂݍ���SE���폜
	DeleteSoundMem(select_se);
	DeleteSoundMem(decision_se);

	//���I�������̉��
	delete ranking;
}

//���݂̃V�[�������擾
const eSceneType RankingInputScene::GetNowSceneType() const
{
	return eSceneType::eRanking_Input;
}

//���O���͏���
bool RankingInputScene::InputName()
{
	// ���͏��擾
	int Key = GetJoypadInputState(DX_INPUT_PAD1);

	//�J�[�\�����쏈��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_LEFT))
	{
		// �J�[�\�����炷
		//PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
		if (cursor_y == 4 && cursor_x == 0)
		{
			cursor_x = 1;
		}
		else if (cursor_x > 0)
		{
			cursor_x--;
		}
		else
		{
			cursor_x = 12;
		}
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT))
	{
		// �J�[�\�����炷
		//PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
		if (cursor_y == 4 && cursor_x == 1)
		{
			cursor_x = 0;
		}
		else if (cursor_x < 12)
		{
			cursor_x++;
		}
		else
		{
			cursor_x = 0;
		}
	}
	// ���͕�������14����������������
	if (name_num < 14) {
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
		{
			if (cursor_y > 0)
			{
				// �J�[�\�����炷
				//PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
				cursor_y--;
			}
		}
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
		{
			if (cursor_y < 4)
			{
				// �J�[�\�����炷
				//PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
				cursor_y++;
				if (cursor_y == 4)
				{
					cursor_x = 0;
				}
			}
		}
	}

	//�J�[�\���ʒu�̕��������肷��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		// ���艹�炷
		//PlaySoundMem(decision_se, DX_PLAYTYPE_BACK, TRUE);
		if (cursor_y < 2)
		{
			name[name_num++] = 'a' + cursor_x + (cursor_y * 13);
			if (name_num == 14)
			{
				cursor_x = 0;
				cursor_y = 4;
			}
		}
		else if (cursor_y < 4)
		{
			name[name_num++] = 'A' + cursor_x + ((cursor_y - 2) * 13);
			if (name_num == 14)
			{
				cursor_x = 0;
				cursor_y = 4;
			}
		}
		else
		{
			if (cursor_x == 0) // ����{�^��
			{
				name[name_num] = '\0';
				Finalize();
				return true;
			}
			else // �߂�{�^��
			{
				if (name_num > 0)
				{
					name_num--;
					name[name_num] = NULL;
				}
			}
		}
	}
	return false;
}