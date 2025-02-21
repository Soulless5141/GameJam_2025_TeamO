#include "Gage.h"
#include "DxLib.h"
#include <stdlib.h>

#define GAGE_MAX (100)			// �Q�[�W�̏��
#define GAGE_MIN (0)			// �Q�[�W�̉���

Gage::Gage() :
	meter(0),
	fluctuation(0),
	change_flip_flag(false),
	decision(false)
{
}

Gage::~Gage()
{
}

// ����������
void Gage::Initialize()
{
	// ���[�^�[�̏�����
	meter = 0;

	// �ϓ��l�̃����_���擾
	//fluctuation = rand() % 6 + 1;
	fluctuation = 1;

	change_flip_flag = false;

	decision = false;
}

// �X�V����
void Gage::Update()
{
	// ���͏��擾
	int Key = GetJoypadInputState(DX_INPUT_PAD1);

	// A�{�^���������ꂽ��l��ϓ����Ȃ��悤�ɂ���
	if (Key & PAD_INPUT_A)
	{
		decision = true;
	}

	// A�{�^����������Ă��Ȃ�������Q�[�W�𓮂���
	if (!decision)
	{
		ChangeMove();
	}
}

// �`�揈��
void Gage::Draw()
{
	DrawBox(100, 200, 120, 200, GetColor(0, 0, 0), false);

	// �Q�[�W�̓���������`��
	DrawBox(100, 200, 120, 200 - meter, GetColor(255, 0, 0), false);
}

// �I������
void Gage::Finalize()
{

}

// �Q�[�W�̕ϓ�����
void Gage::ChangeMove()
{
	// �Q�[�W�ϓ�
	meter += fluctuation;

	// �Q�[�W���㏸���邩���~���邩�̔���
	if (change_flip_flag == false)
	{
		// �Q�[�W��Max�ȏ�ɂȂ�����
		if (meter >= GAGE_MAX)
		{
			meter = GAGE_MAX;			// ����ɂ���
			fluctuation *= -1;			// �ϓ��l�̔��]
			change_flip_flag = true;	// �Q�[�W�����~�ɂ���
		}
	}
	else
	{
		// �Q�[�W��Min�ȉ��ɂȂ�����
		if (meter <= GAGE_MIN)
		{
			meter = GAGE_MIN;			// �����ɂ���
			fluctuation *= -1;			// �ϓ��l�̔��]
			change_flip_flag = false;	// �Q�[�W���㏸�ɂ���
		}
	}
}
