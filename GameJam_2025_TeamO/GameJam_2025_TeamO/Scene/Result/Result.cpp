#include "Result.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

//int result_background_image;  //�w�i�ݒ�p�̕ϐ�
//int result_bgm;               //BGM�ݒ�p�̕ϐ�
//
//void ResultSceneInit(void)
//{
//
//}
//
//eSceneType ResultSceneUpdate(void)
//{
//	return eResult;
//}
//
//void ResultSceneDraw(void)
//{
//	DrawFormatString(100, 100, GetColor(255, 255, 255), "���U���g���");
//}

Result::Result() : back_ground(NULL), score(0), mileage(0)
{
	//for (int i = 0; i < 3; i++)
	//{
	//	enemy_image[i] = NULL;
	//	enemy_count[i] = NULL;
	//}
}

Result::~Result()
{

}

//����������
void Result::Initialize()
{
	//�摜�̓ǂݍ���
	//back_ground = LoadGraph("Resource/images/back.bmp");

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
	//DrawGraph(0, 0, back_ground, TRUE);


	DrawFormatString(180, 290, 0x000000, "      = %6d", score);
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