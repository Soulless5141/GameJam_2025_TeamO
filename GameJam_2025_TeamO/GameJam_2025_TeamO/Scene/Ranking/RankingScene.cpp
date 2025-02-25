#include "RankingScene.h"
#include "../SceneBase.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

RankingScene::RankingScene() : background_image(NULL), ranking(nullptr)
{

}

RankingScene::~RankingScene()
{

}

//����������
void RankingScene::Initialize()
{
	//�摜�̓ǂݍ���
	//background_image = LoadGraph("Resource/images/Ranking.png");

	////�G���[�`�F�b�N
	//if (background_image == -1)
	//{
	//	throw("Resource/images/Ranking.png������܂���\n");
	//}

	//�����L���O�����擾
	ranking = new RankingData;
	ranking->Initialize();
}

//�X�V����
eSceneType RankingScene::Update(const float& delta_second)
{
	// ���͏��擾
	int Key = GetJoypadInputState(DX_INPUT_PAD1);

	//B�{�^���������ꂽ��A�^�C�g���ɖ߂�
	if (Key & PAD_INPUT_B)
	{
		return eSceneType::eTitle;
	}
	return GetNowSceneType();
}

//�`�揈��
void RankingScene::Draw() const
{
	//�w�i�摜�̕`��
	//DrawGraph(0, 0, background_image, FALSE);
	DrawBox(0, 0, 1000, 700, GetColor(255, 255, 255), true);

	SetFontSize(48);
	DrawString(200, 50, "�����L���O", 0x000000);


	SetFontSize(16);

	//�擾���������L���O�f�[�^��`�悷��
	for (int i = 0; i < 5; i++)
	{
		DrawFormatString(50, 170 + i * 25, 0x000000, "%2d %6d %-15s", ranking->GetRank(i), ranking->GetScore(i), ranking->GetName(i));
	}
}

//�I������
void RankingScene::Finalize()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);

	//���I�������̉��
	ranking->Finalize();
	delete ranking;
}

//���݂̃V�[�������擾
const eSceneType RankingScene::GetNowSceneType() const
{
	return eSceneType::eRanking_Scene;
}