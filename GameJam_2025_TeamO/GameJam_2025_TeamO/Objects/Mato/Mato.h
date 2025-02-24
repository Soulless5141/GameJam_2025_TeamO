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
	//std::vector<int> image[3];
	int mato_image[3];  //�摜
	int a_image;
	int score;    //�X�R�A
	int i_image[3];
	int s_score;  //
	int hp;       //�I��HP
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

	void SetTargetData(int value);

private:
	void AnimationControl(float delta_second); //�A�j���[�V����
};