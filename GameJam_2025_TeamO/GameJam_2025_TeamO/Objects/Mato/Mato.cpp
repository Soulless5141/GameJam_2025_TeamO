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
	mato_image[3] = rm->GetImages("Resource/Images/keihin4.png")[0];
	//hit_state = eHitState::none; //�q�b�g��ԂȂ�
	//eObjectType::mato; //�I�u�W�F�N�g�̐ݒ�

	int a = GetRand(3); //�����_������10���炢
	SetTargetData(a);

	box_size = Vector2D(700, 800) * 0.2f;
}

void Mato::Update(float delta_second)
{
	
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

void Mato::SetTargetData(int value)
{
	switch (value)
	{
	case 0:
		score = 10; //10�_
		image = mato_image[0];
		hp = 10;
		break;
	case 1:
		score = 50; //50
		image = mato_image[1];
		hp = 20;
		break;
	case 2:
		score = 100; //100
		image = mato_image[2];
		hp = 30;
		break;
	case 3:
		score = 200; //200
		image = mato_image[3];
		hp = 40;
		break;
	default:
		break;
	}
}

void Mato::AnimationControl(float delta_second)
{

}

void Mato::DecreaseHp(int value)
{
	this->hp -= value;
}