#include "DxLib.h"
#include "RemainingBullets.h"
#include "../../Utility/PadInput.h"

#define MAX_BULLET_LIFE (5)

RemainingBullets::RemainingBullets() : life_bullet(0)
{
	ResourceManager* rm = ResourceManager::GetInstance();

	// �����c�e�ݒ�
	life_bullet = MAX_BULLET_LIFE;

	// �摜�ǂݍ���
	image = rm->GetImages("Resource/Images/bullet.png", 1, 1, 1, 577, 378);
}

RemainingBullets::~RemainingBullets()
{
}

void RemainingBullets::Initialize()
{
	
}

void RemainingBullets::Update()
{
	/*if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		LifeReduce();
	}*/
}

void RemainingBullets::Draw()
{
	DrawBox(930, 15, 1250, 95, GetColor(0, 0, 0), true);

	for (int i = 0; i < life_bullet; i++)
	{
		DrawRotaGraph(970 + (i * 60), 55, 0.12, 1, image[0], TRUE);
	}
	
}

void RemainingBullets::Finalize()
{
}

int RemainingBullets::GetLife()
{
	return life_bullet;
}

void RemainingBullets::LifeReduce()
{
	life_bullet--;
}
