#include "Player.h"
#include "DxLib.h"
#include "../../Utility/PadInput.h"
#include "math.h"

#define PLAYER_SCREEN_WIDTH 1200
#define PLAYER_SCREEN_HEIGHT 640

Player* Player::instance = nullptr;

Player::Player()
{
    pushFlg = FALSE;

    //playerX = 570.0f;
    //playerY = 320.0f;
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

void Player::Initialize()
{
    ResourceManager* rm = ResourceManager::GetInstance();
    playerImg = rm->GetImages("Resource/Images/scope.png")[0];
    image = playerImg;

    box_size = Vector2D(577.0f, 577.0f) * 0.2f;
}

void Player::Update(float delta_second)
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

    location.x += px;
    location.y += py;

    // 画面外に出ないようにする
    if (location.x > PLAYER_SCREEN_WIDTH) {
        location.x = PLAYER_SCREEN_WIDTH;
        px = 0.0f;
    }
    if (location.x < 80) {
        location.x = 80;
        px = 0.0f;
    }


    // 画面外に出ないようにする
    if (location.y > PLAYER_SCREEN_HEIGHT) {
        location.y = PLAYER_SCREEN_HEIGHT;
        py = 0.0f;
    }
    if (location.y < 80) {
        location.y = 80;
        py = 0.0f;
    }

}

void Player::Draw(const Vector2D& screen_offset) const
{
    DrawGraph(0, 0, background, FALSE);  // 背景を描画
    //DrawGraph(playerCursorX, playerCursorY, player, TRUE);  // プレイヤー画像を描画
    //DrawCircleAA(playerX, playerY, 15, 100, GetColor(255, 0, 0), TRUE);

    //DrawGraphF(playerX, playerY, playerImg, FALSE);

    //// オフセット値を基に画像の描画を行う
    //Vector2D graph_location = this->location + screen_offset;
    //DrawRotaGraphF(playerX, playerY, 1.0, 0.0, image, TRUE, this->flip_flag);

    __super::Draw(screen_offset);
}

void Player::SetLocation(Vector2D new_location)
{
    location = new_location;
}

Player* Player::GetInstance()
{
    // インスタンスが生成されていない場合、生成する
    if (instance == nullptr)
    {
        instance = new Player();
    }

    return instance;
}