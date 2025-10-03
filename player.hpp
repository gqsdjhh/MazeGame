#pragma once
#include <utility>
#include "observer.hpp"  // 引入观察者接口

class Player : public Observable {  // 继承可观察接口
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
