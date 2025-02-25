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
	//hit_state = eHitState::none; //ヒット状態なし
	//eObjectType::mato; //オブジェクトの設定

	int a = GetRand(3); //ランダム生成10個くらい
	SetTargetData(a);

	box_size = Vector2D(700, 800) * 0.2f;
}

void Mato::Update(float delta_second)
{
	
	//if (hit_state==eHitState::hit) //当たった時の処理
	//{
	//	Mato::AnimationControl(); //アニメーション
	//	s_score += score; //スコアの計算
	//}
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
	switch (value)
	{
	case 0:
		score = 10; //10点
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
		score = 25; //25
		image = mato_image[3];
		hp = 10;
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