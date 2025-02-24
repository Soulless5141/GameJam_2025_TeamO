#include "DxLib.h"
#include "RemainingBullets.h"

#define MAX_BULLET_LIFE (5)

RemainingBullets::RemainingBullets() : life_bullet(0)
{
}

RemainingBullets::~RemainingBullets()
{
}

void RemainingBullets::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();
	life_bullet = MAX_BULLET_LIFE;

	image = rm->GetImages("Resource/Images/bullet.png", 1, 1, 1, 577, 378);
	
}

void RemainingBullets::Update()
{
	int Key = GetJoypadInputState(DX_INPUT_PAD1);

	if (Key & PAD_INPUT_A)
	{
		life_bullet--;
	}
}

void RemainingBullets::Draw()
{
	for (int i = 0; i < life_bullet; i++)
	{
		DrawRotaGraph(20 + (i * 20), 400, 1.0, 0, image[0], TRUE);
	}
	
}

void RemainingBullets::Finalize()
{
}
