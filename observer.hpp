#pragma once
#include <vector>
#include <algorithm>
#include <graphics.h>

// 前向声明
class Player;

// 观察者接口
class Observer {
public:
    virtual void onPlayerLivesChanged(const Player& player) = 0;
    virtual void onGameOver(bool isWin) = 0;
    virtual ~Observer() = default;
};

// 可观察对象接口
class Observable {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    // 通知生命值变化
    void notifyLivesChanged(const Player& player);
    // 通知游戏结束
    void notifyGameOver(bool isWin);
};

class UIObserver : public Observer {
public:
    void onPlayerLivesChanged(const Player& player) override;
    void onGameOver(bool isWin) override;
};
