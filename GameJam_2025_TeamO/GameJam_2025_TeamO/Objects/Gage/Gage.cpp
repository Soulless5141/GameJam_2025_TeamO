#include "Gage.h"
#include "DxLib.h"
#include <stdlib.h>

#define GAGE_MAX (100)			// �Q�[�W�̏��
#define GAGE_MIN (1)			// �Q�[�W�̉���

Gage::Gage() :
	meter(0),
	fluctuation(0),
	change_flip_flag(false),
	decision(false)
{
	// ���[�^�[�̏�����
	meter = 1;

	// �ϓ��l�̃����_���擾
	fluctuation = rand() % 4 + 3;

	change_flip_flag = false;

	decision = false;
}

Gage::~Gage()
{
}

// ����������
void Gage::Initialize()
{
	
}

// �X�V����
void Gage::Update()
{
	// ���͏��擾
	int Key = GetJoypadInputState(DX_INPUT_PAD1);

	// A�{�^���������ꂽ��l��ϓ����Ȃ��悤�ɂ���
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		decision = true;
	}

	if (PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
	{
		decision = false;
	}

	// �f�o�b�O�p
	if (Key & PAD_INPUT_B)
	{
		decision = false;
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
	// �Q�[�W�̌��̍����l�p
	//DrawBox(280, 650, 200, 120, GetColor(0, 0, 0), true);
	DrawBox(30, 50, 630, 100, GetColor(0, 0, 0), true);


	// �Q�[�W�̘g��
	//DrawBox(280, 650, 200, 120, GetColor(255, 0, 0), false);
	DrawBox(30, 50, 630, 100, GetColor(255, 0, 0), false);

	// �Q�[�W�̓���������`��
	//DrawBox(280, 650, 200, 650 - (530 * (0.01 * meter)), GetColor(255, 0, 0), true);
	DrawBox(30, 50, 30 + (600 * (0.01 * meter)), 100, GetColor(255, 0, 0), true);
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

int Gage::GetMeter()
{
	return meter;
}
