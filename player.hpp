#pragma once
#include <utility>
#include "observer.hpp"  // 观察者模式接口

// 玩家类，继承可观察接口（观察者模式）
class Player : public Observable {
public:
    // 构造函数，初始化起始坐标(默认(1,1))
    Player(int startX = 1, int startY = 1);
    // 获取当前坐标
    std::pair<int, int> GetXY() const;

    // 移动玩家(dx/dy为坐标变化量)
    void Move(int dx, int dy);
    // 获取剩余生命数
    int GetLives() const;
    // 减少一条生命
    void LoseLife();
    // 判断是否存活
    bool IsAlive();
    // 显示玩家信息
    void PlayerDisplay() const;
    // 默认析构函数
    ~Player() = default;

private:
    int _x;      // x坐标
    int _y;      // y坐标
    int _lives;  // 生命数
};
