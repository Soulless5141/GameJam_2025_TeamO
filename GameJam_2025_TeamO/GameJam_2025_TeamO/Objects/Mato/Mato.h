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
	int mato_image[4];  //�摜
	int m_score;    //�X�R�A
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

	Vector2D GetboxSize() const
	{
		return this->box_size;
	}

	void SetTargetData(int value);

	void DecreaseHp(int value);

private:
	void AnimationControl(float delta_second); //�A�j���[�V����
};