#include "Player.h"
#include "DxLib.h"
#include "../../Utility/PadInput.h"

#define PLAYER_SCREEN_WIDTH 1200
#define PLAYER_SCREEN_HEIGHT 640

Player::Player()
{
    player = LoadGraph("Resource/Images/scope.png");
    playerCursorX = 570;
    playerCursorY = 320;  // ‰æ–Ê’†‰›‚É•ÏX
    speed = 10;
    pushFlg = FALSE;
}

void Player::Update()
{
    int Key = GetJoypadInputState(DX_INPUT_PAD1);

    // XŽ²‚ÌˆÚ“®ˆ—
    if (Key & PAD_INPUT_RIGHT) {
        playerCursorX += speed;
    }
    else if (Key & PAD_INPUT_LEFT) {
        playerCursorX -= speed;
    }

    // ‰æ–ÊŠO‚Éo‚È‚¢‚æ‚¤‚É‚·‚é
    if (playerCursorX > PLAYER_SCREEN_WIDTH) {
        playerCursorX = PLAYER_SCREEN_WIDTH;
    }
    if (playerCursorX < 80) {
        playerCursorX = 80;
    }

    // YŽ²‚ÌˆÚ“®ˆ—
    if (Key & PAD_INPUT_UP) {
        playerCursorY -= speed;  // ã‚ÉˆÚ“®
    }
    else if (Key & PAD_INPUT_DOWN) {
        playerCursorY += speed;  // ‰º‚ÉˆÚ“®
    }

    // ‰æ–ÊŠO‚Éo‚È‚¢‚æ‚¤‚É‚·‚é
    if (playerCursorY > PLAYER_SCREEN_HEIGHT) {
        playerCursorY = PLAYER_SCREEN_HEIGHT;
    }
    if (playerCursorY < 80) {
        playerCursorY = 80;
    }
}

void Player::Draw() const
{
    DrawGraph(0, 0, background, FALSE);  // ”wŒi‚ð•`‰æ
    DrawGraph(playerCursorX, playerCursorY, player, TRUE);  // ƒvƒŒƒCƒ„[‰æ‘œ‚ð•`‰æ
}
