#include"Mato.h"
#include"DxLib.h"
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
	image[0] = LoadGraph("Resource/Images/keihin1.png");
	image[1] = LoadGraph("Resource/Images/keihin2.png");
	image[2] = LoadGraph("Resource/Images/keihin3.png");
	//hit_state = eHitState::none; //�q�b�g��ԂȂ�
	//eObjectType::mato; //�I�u�W�F�N�g�̐ݒ�
}

void Mato::Update()
{
	srand((unsigned int)time(NULL)); //�����_������������
	int a;
	a = rand() % 3; //�����_������10���炢

	switch (a)
	{
	case 1:
		score = 10; //10�_
		a_image = image[0];
		break;
	case 2:
		score = 50; //50
		a_image = image[1];
		break;
	case 3:
		score = 100; //100
		a_image = image[2];
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

void Mato::Draw()
{
	// �e�N���X�̕`�揈�����Ăяo��
	//__super::Draw(screen_offset);
}

void Mato::Finalize()
{

}

void Mato::OnHitCollision(GameObjectBase* hit_object)
{

}

void Mato::AnimationControl()
{

}