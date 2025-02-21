#pragma once

enum eHitState
{
	hit, 
	none,
};

class Mato
{
private:
	int image;  //‰æ‘œ
	//Vector2D box_size;
	eHitState hit_state;

public:
	Mato();
	~Mato();

	void Initialize();
	void Update();
	void Draw();
	void Finalize();

	virtual void OnHitCollision();

private:
	void AnimationControl();
};