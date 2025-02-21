#pragma once
class Player
{
private:
private:
    int background;
    int player;
    int playerCursorX;
    int playerCursorY;
    int speed;

public:
    Player();

public:
    void Update();
    void Draw() const;
};