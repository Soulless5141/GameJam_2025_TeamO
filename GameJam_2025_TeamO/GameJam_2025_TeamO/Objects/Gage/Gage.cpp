#include "Gage.h"
#include "DxLib.h"
#include <stdlib.h>

#define GAGE_MAX (100)
#define GAGE_MIN (0)


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

void Gage::Initialize()
{
	meter = 0;
	//fluctuation = rand() % 6 + 1;
	fluctuation = 1;
}

void Gage::Update()
{
	// “ü—ÍXV
	PAD_INPUT::UpdateKey();

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		decision = true;
	}

	if (!decision)
	{
		ChangeMove();
	}
}

void Gage::Draw()
{
	DrawBox(100, 200, 100, 200 - meter, GetColor(255, 0, 0), false);
}

void Gage::Finalize()
{

}

void Gage::ChangeMove()
{
	meter += fluctuation;

	if (change_flip_flag == false)
	{
		if (meter >= GAGE_MAX)
		{
			meter = GAGE_MAX;
			change_flip_flag = true;
		}
	}
	else
	{
		if (meter <= GAGE_MIN)
		{
			meter = GAGE_MIN;
			change_flip_flag = false;
		}
	}
}
