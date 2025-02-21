#include "Player.h"
#include"DxLib.h"
#define PLAYER_SCREEN_WIDTH 1200
#define PLAYER_SCREEN_HEIGHT 640

Player::Player()
{
	background = LoadGraph("");
	player = LoadGraph("");
	playerCursorX = 570;
	playerCursorY = 680;
	speed = 10;
	pushFlg = FALSE;
}

void Player::Update()
{
	int Key = GetJoypadInputState(DX_INPUT_PAD1);
	// X���̈ړ�����
	if (Key & PAD_INPUT_RIGHT) {

		// �E�������Ă�����E�ɐi��
		playerCursorX += speed;
	}
	else if (Key & PAD_INPUT_LEFT) {

		// ���������Ă����獶�ɐi��
		playerCursorX -= speed;
	}

	if (playerCursorX > PLAYER_SCREEN_WIDTH) {

		//�E�̕�
		playerCursorX = PLAYER_SCREEN_WIDTH;
	}
	if (playerCursorX < 80) {
		//���̕�
		playerCursorX = 80;
	}

	// Y���̈ړ�����
	if (Key & PAD_INPUT_UP) {

		// �E�������Ă�����E�ɐi��
		playerCursorY += speed;
	}
	else if (Key & PAD_INPUT_DOWN) {

		// ���������Ă����獶�ɐi��
		playerCursorY -= speed;
	}

	if (playerCursorY > PLAYER_SCREEN_HEIGHT) {

		//�E�̕�
		playerCursorY = PLAYER_SCREEN_HEIGHT;
	}
	if (playerCursorY < 80) {
		//���̕�
		playerCursorY = 80;
	}
}

void Player::Draw()const
{
	DrawCircle(playerCursorX, playerCursorY, 0xff0000, FALSE);
}