#pragma once
class Player
{
private:
private:
    int background;
    int player;

    float playerX;      //x座標
    float playerY;      //y座標
    float px, py;       //移動量
    float mv;           //加速度

    int angle;          //角度

    //サイン、コサインテーブル作成
    float fsin[360], fcos[360];

    int pushFlg;

public:
    Player();

public:
    void Update();
    void Draw() const;
};