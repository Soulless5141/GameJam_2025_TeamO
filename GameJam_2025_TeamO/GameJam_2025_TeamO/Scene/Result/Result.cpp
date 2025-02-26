#include "Result.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include"../../Objects/Mato/Mato.h"
#include "DxLib.h"



Result::Result() : back_ground(NULL), score(0), mileage(0)
{

}

Result::~Result()
{

}

//����������
void Result::Initialize()
{
	//�摜�̓ǂݍ���
	back_ground = LoadGraph("Resource/images/score_bgi.jpg");

	//�Q�[�����ʂ̓ǂݍ���
	ReadResultData();
}

//�X�V����
eSceneType Result::Update(const float& delta_second)
{

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return eTitle;
	}


	return GetNowSceneType();
}

//�`�揈��
void Result::Draw() const
{
	//�w�i�摜��`��
	DrawRotaGraph(640, 360, 0.77, 0, back_ground, 0, 0);

	//�X�R�A�̕`��
	SetFontSize(64);
	DrawFormatString(200, 390, 0x000000, "      = %6d", score);

	SetFontSize(48);
	DrawFormatString(1000, 600, GetColor(0, 0, 0), "B�F�߂�");
}
//�I��������
void Result::Finalize()
{

}

//���݃V�[�������擾
eSceneType const Result::GetNowSceneType() const
{
	//�X�R�A��5�ʈȏ�Ȃ�Ń����L���O�ɑJ�ڂ���
	for (int i = 0; i < 5; i++)
	{
		if (score > r_score[i])
		{
			return eSceneType::eRanking_Input;
		}
	}

	return eSceneType::eResult;
}

//���U���g�f�[�^�̓ǂݍ���
void Result::ReadResultData()
{
	//�t�@�C���I�[�v��
	FILE* fp = nullptr;
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

void Result::ReadRankingData()
{
	//�t�@�C���I�[�v��
	FILE* fp = nullptr;
	errno_t result = fopen_s(&fp, "Resource/Data/ranking_data.csv", "r");

	//�G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/Data/ranking_data.csv���ǂݍ��߂܂���\n");
	}

	//���ʂ�ǂݍ���
	for (int i = 0; i < 5; i++)
	{
		int rank[5];
		char str[256] = {};
		fscanf_s(fp, "%d,%d,%[^,]\n", &r_score[i], &rank[i], str[i], 256);
	}
	
	//�t�@�C���N���[�Y
	fclose(fp);
}