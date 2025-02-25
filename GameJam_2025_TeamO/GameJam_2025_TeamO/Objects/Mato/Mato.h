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
	static int mato_image[3];  //画像
	static int score;    //スコア
	static int i_image[3];
	static int s_score;  //
	static int hp;       //的のHP
	Vector2D location;
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

	Vector2D GetLocation()const
	{
		return location;
	}
	Vector2D GetBoxsize() const
	{
		return box_size;
	}

	void SetTargetData(int value);

private:
	void AnimationControl(float delta_second); //アニメーション
};