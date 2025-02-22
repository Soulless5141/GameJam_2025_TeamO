#pragma once
#include"../GameObject.h"

enum eHitState
{
	hit, 
	none,
};

class Mato:public GameObject
{
private:
	int image[3];  //画像
	int a_image;
	int score;  //スコア
	int s_score; //
	//Vector2D box_size;
	eHitState hit_state;

public:
	Mato();
	~Mato();

	void Initialize();
	void Update();
	void Draw();
	void Finalize();

	virtual void OnHitCollision(GameObjectBase* hit_object) override;

private:
	void AnimationControl(); //アニメーション
};