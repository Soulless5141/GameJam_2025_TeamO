#pragma once
#include "../../Utility/Vector2D.h"
#include"../GameObject.h"
#include"../../Utility/ResourceManager.h"


class Player: public GameObject 
{
private:
    int background;
    int playerImg;

    //float playerX;      //x座標
    //float playerY;      //y座標
    float px, py;       //移動量
    float mv;           //加速度

    int angle;          //角度

    Vector2D plocation;
    Vector2D box_size;

    //サイン、コサインテーブル作成
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