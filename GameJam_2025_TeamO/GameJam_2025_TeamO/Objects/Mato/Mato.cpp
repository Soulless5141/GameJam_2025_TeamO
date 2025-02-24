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
	//hit_state = eHitState::none; //ヒット状態なし
	//eObjectType::mato; //オブジェクトの設定
	//a_image = NULL;

	image = mato_image[0];
}

void Mato::Update(/*float delta_second*/)
{
	srand((unsigned int)time(NULL)); //ランダム生成初期化
	int a;
	a = rand() % 3; //ランダム生成10個くらい

	switch (a)
	{
	case 1:
		score = 10; //10点
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

void Mato::AnimationControl(float delta_second)
{

}