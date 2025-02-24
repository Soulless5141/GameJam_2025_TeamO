#pragma once
#include "../../Utility/Vector2D.h"

class Player
{
private:
    int background;
    int player;

    float playerX;      //x���W
    float playerY;      //y���W
    float px, py;       //�ړ���
    float mv;           //�����x

    int angle;          //�p�x

    Vector2D location;
    Vector2D size;

    //�T�C���A�R�T�C���e�[�u���쐬
    float fsin[360], fcos[360];

    int pushFlg;

public:
    Player();

public:
    void Update();
    void Draw() const;

    Vector2D GetLocation() const 
    {
        return location;
    }

    Vector2D GetSize() const
    {
        return size;
    }

    void SetLocation(Vector2D new_location);
};