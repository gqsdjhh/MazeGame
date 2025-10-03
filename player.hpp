#pragma once
#include <utility>
#include "observer.hpp"  // ����۲��߽ӿ�

class Player : public Observable {  // �̳пɹ۲�ӿ�
public:
    Player(int startX = 1, int startY = 1);
    std::pair<int, int> GetXY() const;
    void Move(int dx, int dy);
    int GetLives() const;
    void LoseLife();
    bool IsAlive();
    void PlayerDisplay() const;
    ~Player() = default;
private:
    int _x;
    int _y;
    int _lives;
};
