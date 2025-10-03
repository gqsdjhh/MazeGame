#pragma once
#include <utility>
#include "observer.hpp"  // 引入观察者接口

class Player : public Observable {  // 继承可观察接口
public:
    Player(int startX = 1, int startY = 1);
    std::pair<int, int> getXY() const;
    void move(int dx, int dy);
    int getLives() const;
    void loseLife();
    bool isAlive();
    void Playerdisplay() const;
    ~Player() = default;
private:
    int _x;
    int _y;
    int _lives;
};
