#pragma once
#include "../../Utility/Vector2D.h"
#include"../GameObject.h"
#include"../../Utility/ResourceManager.h"


class Player: public GameObject 
{
private:
    int background;
    int playerImg;

    //float playerX;      //x���W
    //float playerY;      //y���W
    float px, py;       //�ړ���
    float mv;           //�����x

    int angle;          //�p�x

    Vector2D plocation;
    Vector2D box_size;

    //�T�C���A�R�T�C���e�[�u���쐬
    float fsin[360], fcos[360];

    int pushFlg;

    static Player* instance;

public:
    Player();

public:
    virtual void Initialize();
    virtual void Update(float delta_second);
    void Draw(const Vector2D& screen_offset) const override;

    Vector2D GetPLocation() const 
    {
        return plocation;
    }

    Vector2D GetboxSize() const
    {
        return this->box_size;
    }

    static Player* GetInstance();

    void SetLocation(Vector2D new_location);
};