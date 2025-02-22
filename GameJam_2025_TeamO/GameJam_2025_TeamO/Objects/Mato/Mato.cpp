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
	//hit_state = eHitState::none; //ヒット状態なし
	//eObjectType::mato; //オブジェクトの設定
}

void Mato::Update()
{
	srand((unsigned int)time(NULL)); //ランダム生成初期化
	int a;
	a = rand() % 3; //ランダム生成10個くらい

	switch (a)
	{
	case 1:
		score = 10; //10点
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

	//if (hit_state==eHitState::hit) //当たった時の処理
	//{
	//	Mato::AnimationControl(); //アニメーション
	//	s_score += score; //スコアの計算
	//}
}

void Mato::Draw()
{
	// 親クラスの描画処理を呼び出す
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