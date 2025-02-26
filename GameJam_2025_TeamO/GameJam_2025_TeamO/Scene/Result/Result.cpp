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

	//B�{�^���Ń����L���O�ɑJ�ڂ���
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return eSceneType::eRanking_Input;
	}

	return GetNowSceneType();
}

//�`�揈��
void Result::Draw() const
{
	//�w�i�摜��`��
	DrawRotaGraph(640, 360, 0.77, 0, back_ground, 0, 0);

	//�X�R�A�̕`��
	DrawFormatString(180, 290, 0x000000, "      = %6d", score);
	DrawFormatString(1000, 680, GetColor(0, 0, 0), "B�F�߂�");
}
//�I��������
void Result::Finalize()
{

}

//���݃V�[�������擾
eSceneType const Result::GetNowSceneType() const
{
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