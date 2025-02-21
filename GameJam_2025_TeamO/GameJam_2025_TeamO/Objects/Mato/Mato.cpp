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
	image = LoadGraph("Resource/Images/keihin1.png");
	hit_state = eHitState::none; 

	
}

void Mato::Update()
{
	srand((unsigned int)time(NULL)); //ランダム生成初期化
	int a;
	a = rand() % 3; //10個くらい

	switch (a)
	{
	case 1:
		score = 10; //10点
		break;
	case 2:
		score = 50; //50
		break;
	case 3:
		score = 100; //100
	}
}

void Mato::Draw()
{
	// 親クラスの描画処理を呼び出す
	//__super::Draw(screen_offset);
}

void Mato::Finalize()
{

}

void Mato::OnHitCollision()
{

}

void Mato::AnimationControl()
{

}