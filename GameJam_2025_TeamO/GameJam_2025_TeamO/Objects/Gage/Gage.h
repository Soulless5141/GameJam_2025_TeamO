#pragma once
class Gage
{
private:
	int meter;				// ゲージの中身
	int fluctuation;        // ゲージの変動値
	bool change_flip_flag;  // ゲージが増えてるか減っているのか

public:
	Gage();
	~Gage();

	void Initialize();
	void Update();
	void Draw();
	void Finalize();

	void ChangeMove();
};

