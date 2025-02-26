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

	int a = GetRand(3); //ランダム生成10個くらい
	SetTargetData(a);

	//当たり判定
	box_size = Vector2D(700, 800) * 0.2f;
}

void Mato::Update(float delta_second)
{

}

void Mato::Draw(const Vector2D& screen_offset) const
{
	// 親クラスの描画処理を呼び出す
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
	//的のランダム表示,HPとScoreの設定
	switch (value)
	{
	case 0:
		info.m_score = 10; //10点
		image = mato_image[0];
		info.hp = 20;
		break;
	case 1:
		info.m_score = 50; //50
		image = mato_image[1];
		info.hp = 75;
		break;
	case 2:
		info.m_score = 100; //100
		image = mato_image[2];
		info.hp = 90;
		break;
	case 3:
		info.m_score = 25; //25
		image = mato_image[3];
		info.hp = 40;
		break;
	default:
		break;
	}
}

void Mato::AnimationControl(float delta_second)
{

}

int Mato::DecreaseHp(int value)
{
	//Hpを減らす処理
	info.hp -= value;
	if (info.hp < 0)
	{
		info.hp = 0;
	}

	return info.hp;
}

//HP情報取得
int Mato::GetHp() const
{
	return info.hp;
}

//Score情報取得
int Mato::GetScore() const
{
	return info.m_score;
}