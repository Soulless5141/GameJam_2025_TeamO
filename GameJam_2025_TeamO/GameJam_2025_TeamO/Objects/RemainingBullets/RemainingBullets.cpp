#include "DxLib.h"
#include "RemainingBullets.h"
#include "../../Utility/PadInput.h"

#define MAX_BULLET_LIFE (10)

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

}

void RemainingBullets::Draw()
{
	// ���̍����l�p
	DrawBox(930, 15, 1230, 95, GetColor(0, 0, 0), true);

	// �e�ۉ摜�`��
	DrawRotaGraph(970, 55, 0.14, 1, image[0], TRUE);

	// �c��e�ې��̕`��
	SetFontSize(90);
	DrawFormatString(1015, 10, GetColor(255,255,255), "�~%d",life_bullet);
	
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
