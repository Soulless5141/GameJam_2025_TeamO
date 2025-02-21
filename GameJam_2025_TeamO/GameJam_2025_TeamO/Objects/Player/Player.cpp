#include "Player.h"
#include "DxLib.h"
#include "../../Utility/PadInput.h"

#define PLAYER_SCREEN_WIDTH 1200
#define PLAYER_SCREEN_HEIGHT 640

Player::Player()
{
    player = LoadGraph("Resource/Images/scope.png");
    playerCursorX = 570;
    playerCursorY = 320;  // 画面中央に変更
    speed = 10;
    pushFlg = FALSE;
}

void Player::Update()
{
    int Key = GetJoypadInputState(DX_INPUT_PAD1);

    // X軸の移動処理
    if (Key & PAD_INPUT_RIGHT) {
        playerCursorX += speed;
    }
    else if (Key & PAD_INPUT_LEFT) {
        playerCursorX -= speed;
    }

    // 画面外に出ないようにする
    if (playerCursorX > PLAYER_SCREEN_WIDTH) {
        playerCursorX = PLAYER_SCREEN_WIDTH;
    }
    if (playerCursorX < 80) {
        playerCursorX = 80;
    }

    // Y軸の移動処理
    if (Key & PAD_INPUT_UP) {
        playerCursorY -= speed;  // 上に移動
    }
    else if (Key & PAD_INPUT_DOWN) {
        playerCursorY += speed;  // 下に移動
    }

    // 画面外に出ないようにする
    if (playerCursorY > PLAYER_SCREEN_HEIGHT) {
        playerCursorY = PLAYER_SCREEN_HEIGHT;
    }
    if (playerCursorY < 80) {
        playerCursorY = 80;
    }
}

void Player::Draw() const
{
    DrawGraph(0, 0, background, FALSE);  // 背景を描画
    DrawGraph(playerCursorX, playerCursorY, player, TRUE);  // プレイヤー画像を描画
}
