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
	background_image = LoadGraph("Resource/images/Ranking.jpg");

	//�G���[�`�F�b�N
	if (background_image == -1)
	{
		throw("Resource/images/Ranking.png������܂���\n");
	}

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
	DrawExtendGraph(0, 0, 1280, 720, background_image, FALSE);

	SetFontSize(40);

	//�擾���������L���O�f�[�^��`�悷��
	for (int i = 0; i < 5; i++)
	{
		DrawFormatString(380, 200 + i * 92, 0x000000, "�X�R�A: %4d   ���O: %-15s", ranking->GetScore(i), ranking->GetName(i));
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