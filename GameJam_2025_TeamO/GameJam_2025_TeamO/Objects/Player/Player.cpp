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
        //0�x����359�x�܂ł�sin�Ecos�̒l�����O�v�Z���A�z��ɕۑ�
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
        //�E��
        angle = 45;
    }
    else if((Key &PAD_INPUT_LEFT) && (Key & PAD_INPUT_UP))
    {
        //����
        angle = 135;
    }
    else if ((Key & PAD_INPUT_LEFT) &&(Key & PAD_INPUT_DOWN))
    {
        //����
        angle = 225;
    }
    else if ((Key & PAD_INPUT_RIGHT) && (Key & PAD_INPUT_DOWN))
    {
        //�E��
        angle = 315;
    }
    else if (Key & PAD_INPUT_UP)
    {
        //��
        angle = 90;
    }
    else if (Key & PAD_INPUT_DOWN)
    {
        //��
        angle = 270;
    }
    else if (Key & PAD_INPUT_LEFT)
    {
        //��
        angle = 180;
    }
    else if (Key & PAD_INPUT_RIGHT)
    {
        //�E
        angle = 0;
    }

    //angle�̒l���ς���Ă�����ړ��ʂ�ύX����
    if (angle != -1)
    {
        px += fcos[angle] * mv;
        py -= fsin[angle] * mv;
    }

    playerX += px;
    playerY += py;

    // ��ʊO�ɏo�Ȃ��悤�ɂ���
    if (playerX > PLAYER_SCREEN_WIDTH) {
        playerX = PLAYER_SCREEN_WIDTH;
        px = 0.0f;
    }
    if (playerX < 80) {
        playerX = 80;
        px = 0.0f;
    }


    // ��ʊO�ɏo�Ȃ��悤�ɂ���
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
    DrawGraph(0, 0, background, FALSE);  // �w�i��`��
    //DrawGraph(playerCursorX, playerCursorY, player, TRUE);  // �v���C���[�摜��`��
    DrawCircleAA(playerX, playerY, 15, 100, GetColor(255, 0, 0), TRUE);
}

void Player::SetLocation(Vector2D new_location)
{
    location = new_location;
}
