#include "RemainingBullets.h"
#include "../../Utility/ResourceManager.h"

RemainingBullets::RemainingBullets() : life_bullet(0)
{
}

RemainingBullets::~RemainingBullets()
{
}

void RemainingBullets::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();
	life_bullet = 5;

	//image = rm->GetImages("Resource/Images/bullet.png", 1, 1, 1, 32, 32);
	
}

void RemainingBullets::Update()
{
}

void RemainingBullets::Draw()
{
}

void RemainingBullets::Finalize()
{
}
