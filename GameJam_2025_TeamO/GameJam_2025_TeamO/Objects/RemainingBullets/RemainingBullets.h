#pragma once
#include "../../Utility/ResourceManager.h"
#include <string>

class RemainingBullets
{
private:
	int life_bullet; // �c�e
	std::vector<int> image;

public:
	RemainingBullets();
	~RemainingBullets();

	void Initialize();	// ����������
	void Update();		// �X�V����
	void Draw();		// �`�揈��
	void Finalize();	// �I������

	int GetLife();		// �c�e���擾����
	void LifeReduce();	// �c�e�̌�������

};

