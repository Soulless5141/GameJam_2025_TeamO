#pragma once
class RemainingBullets
{
private:
	int life_bullet; // �c�e
	//std::vector<int> image;

public:
	RemainingBullets();
	~RemainingBullets();

	void Initialize();	// ����������
	void Update();		// �X�V����
	void Draw();		// �`�揈��
	void Finalize();	// �I������
};

