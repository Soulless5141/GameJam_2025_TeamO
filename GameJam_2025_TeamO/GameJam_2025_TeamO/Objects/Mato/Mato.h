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
	Vector2D box_size;
	eHitState hit_state;

public:
	Mato();
	virtual ~Mato();

	virtual void Initialize();
	virtual void Update(float delta_second);
	virtual void Draw(const Vector2D& screen_offset) const override;
	void Finalize() override;

	virtual void OnHitCollision(GameObjectBase* hit_object) override;

private:
	void AnimationControl(float delta_second); //�A�j���[�V����
};