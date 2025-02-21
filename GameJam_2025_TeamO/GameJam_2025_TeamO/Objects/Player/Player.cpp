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
	// X軸の移動処理
	if (Key & PAD_INPUT_RIGHT) {

		// 右を押していたら右に進む
		playerCursorX += speed;
	}
	else if (Key & PAD_INPUT_LEFT) {

		// 左を押していたら左に進む
		playerCursorX -= speed;
	}

	if (playerCursorX > PLAYER_SCREEN_WIDTH) {

		//右の壁
		playerCursorX = PLAYER_SCREEN_WIDTH;
	}
	if (playerCursorX < 80) {
		//左の壁
		playerCursorX = 80;
	}

	// Y軸の移動処理
	if (Key & PAD_INPUT_UP) {

		// 右を押していたら右に進む
		playerCursorY += speed;
	}
	else if (Key & PAD_INPUT_DOWN) {

		// 左を押していたら左に進む
		playerCursorY -= speed;
	}

	if (playerCursorY > PLAYER_SCREEN_HEIGHT) {

		//右の壁
		playerCursorY = PLAYER_SCREEN_HEIGHT;
	}
	if (playerCursorY < 80) {
		//左の壁
		playerCursorY = 80;
	}
}

void Player::Draw()const
{
	DrawCircle(playerCursorX, playerCursorY, 0xff0000, FALSE);
}