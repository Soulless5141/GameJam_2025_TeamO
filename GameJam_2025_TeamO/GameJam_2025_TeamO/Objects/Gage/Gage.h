#pragma once
#include "../../Utility/PadInput.h"

class Gage
{
private:
	int meter;				// �Q�[�W�̒��g
	int fluctuation;        // �Q�[�W�̕ϓ��l
	bool change_flip_flag;  // �Q�[�W�������Ă邩�����Ă���̂�
	bool decision;			// A�{�^���������ꂽ��

public:
	Gage();
	~Gage();

	void Initialize();	// ����������
	void Update();		// �X�V����
	void Draw();		// �`�揈��
	void Finalize();	// �I������

	void ChangeMove();	// �Q�[�W�̒l�̕ϓ�����
};

