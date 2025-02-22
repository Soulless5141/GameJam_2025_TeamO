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
	int image[3];  //�摜
	int a_image;
	int score;  //�X�R�A
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
	void AnimationControl(); //�A�j���[�V����
};