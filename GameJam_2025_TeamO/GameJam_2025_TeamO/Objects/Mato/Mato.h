#pragma once
#include"../GameObject.h"

struct MatoInfo
{
	int hp;       //�I��HP
	int m_score;    //�X�R�A���
};


class Mato:public GameObject
{
private:
	MatoInfo info;
	//std::vector<int> image[3];
	int mato_image[4];  //�摜

	Vector2D box_size;  //�����蔻��傫��
	

public:

	Mato();
	virtual ~Mato();

	virtual void Initialize();
	virtual void Update(float delta_second);
	virtual void Draw(const Vector2D& screen_offset) const override;
	void Finalize() override;

	virtual void OnHitCollision(GameObjectBase* hit_object) override;

	int GetHp() const;
	int GetScore() const;


	Vector2D GetboxSize() const
	{
		return this->box_size;
	}

	void SetTargetData(int value);

	int DecreaseHp(int value);

private:
	void AnimationControl(float delta_second); //�A�j���[�V����
};