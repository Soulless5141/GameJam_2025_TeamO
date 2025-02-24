#include"Mato.h"
#include"DxLib.h"
#include"../../Utility/ResourceManager.h"
#include<stdlib.h>
#include<time.h>

Mato::Mato()
{

}

Mato::~Mato()
{

}

void Mato::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();
	mato_image[0] = rm->GetImages("Resource/Images/keihin1.png")[0];
	mato_image[1] = rm->GetImages("Resource/Images/keihin2.png")[0];
	mato_image[2] = rm->GetImages("Resource/Images/keihin3.png")[0];
	//hit_state = eHitState::none; //�q�b�g��ԂȂ�
	//eObjectType::mato; //�I�u�W�F�N�g�̐ݒ�
	//a_image = NULL;

	image = mato_image[0];
}

void Mato::Update(/*float delta_second*/)
{
	srand((unsigned int)time(NULL)); //�����_������������
	int a;
	a = rand() % 3; //�����_������10���炢

	switch (a)
	{
	case 1:
		score = 10; //10�_
		image = mato_image[0];
		break;
	case 2:
		score = 50; //50
		image = mato_image[1];
		break;
	case 3:
		score = 100; //100
		image = mato_image[2];
		break;
	default:
		break;
	}

	//if (hit_state==eHitState::hit) //�����������̏���
	//{
	//	Mato::AnimationControl(); //�A�j���[�V����
	//	s_score += score; //�X�R�A�̌v�Z
	//}
}

void Mato::Draw(const Vector2D& screen_offset) const
{
	// �e�N���X�̕`�揈�����Ăяo��
	__super::Draw(screen_offset);
}

void Mato::Finalize()
{

}

void Mato::OnHitCollision(GameObjectBase* hit_object)
{

}

void Mato::AnimationControl(float delta_second)
{

}