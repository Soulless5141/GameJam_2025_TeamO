#pragma once
class Player
{
private:
private:
    int background;
    int player;

    float playerX;      //x���W
    float playerY;      //y���W
    float px, py;       //�ړ���
    float mv;           //�����x

    int angle;          //�p�x

    //�T�C���A�R�T�C���e�[�u���쐬
    float fsin[360], fcos[360];

    int pushFlg;

public:
    Player();

public:
    void Update();
    void Draw() const;
};