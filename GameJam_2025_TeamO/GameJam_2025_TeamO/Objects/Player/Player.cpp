#include "Player.h"
#include "DxLib.h"
#include "../../Utility/PadInput.h"
#include "math.h"

#define PLAYER_SCREEN_WIDTH 1200
#define PLAYER_SCREEN_HEIGHT 640

Player::Player()
{
    player = LoadGraph("Resource/Images/scope.png");
    pushFlg = FALSE;

    playerX = 570.0f;
    playerY = 320.0f;
    mv = 0.7f;
    px = 0.0f;
    py = 0.0f;

    angle = 0;


    for (int i = 0; i < 360; i++)
    {
        //0度から359度までのsin・cosの値を事前計算し、配列に保存
        fsin[i] = (float)sin(i * 3.1415926535 / 180);
        fcos[i] = (float)cos(i * 3.1415926535 / 180);
    }
}

void Player::Update()
{
    int Key = GetJoypadInputState(DX_INPUT_PAD1);

    angle = -1;

    if ((Key & PAD_INPUT_RIGHT) && (Key & PAD_INPUT_UP))
    {
        //右上
        angle = 45;
    }
    else if((Key &PAD_INPUT_LEFT) && (Key & PAD_INPUT_UP))
    {
        //左上
        angle = 135;
    }
    else if ((Key & PAD_INPUT_LEFT) &&(Key & PAD_INPUT_DOWN))
    {
        //左下
        angle = 225;
    }
    else if ((Key & PAD_INPUT_RIGHT) && (Key & PAD_INPUT_DOWN))
    {
        //右上
        angle = 315;
    }
    else if (Key & PAD_INPUT_UP)
    {
        //上
        angle = 90;
    }
    else if (Key & PAD_INPUT_DOWN)
    {
        //下
        angle = 270;
    }
    else if (Key & PAD_INPUT_LEFT)
    {
        //左
        angle = 180;
    }
    else if (Key & PAD_INPUT_RIGHT)
    {
        //右
        angle = 0;
    }

    //angleの値が変わっていたら移動量を変更する
    if (angle != -1)
    {
        px += fcos[angle] * mv;
        py -= fsin[angle] * mv;
    }

    playerX += px;
    playerY += py;

    // 画面外に出ないようにする
    if (playerX > PLAYER_SCREEN_WIDTH) {
        playerX = PLAYER_SCREEN_WIDTH;
        px = 0.0f;
    }
    if (playerX < 80) {
        playerX = 80;
        px = 0.0f;
    }


    // 画面外に出ないようにする
    if (playerY > PLAYER_SCREEN_HEIGHT) {
        playerY = PLAYER_SCREEN_HEIGHT;
        py = 0.0f;
    }
    if (playerY < 80) {
        playerY = 80;
        py = 0.0f;
    }

}

void Player::Draw() const
{
    DrawGraph(0, 0, background, FALSE);  // 背景を描画
    //DrawGraph(playerCursorX, playerCursorY, player, TRUE);  // プレイヤー画像を描画
    DrawCircleAA(playerX, playerY, 15, 100, GetColor(255, 0, 0), TRUE);
}

void Player::SetLocation(Vector2D new_location)
{
    location = new_location;
}
