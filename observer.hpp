#pragma once
#include <vector>
#include <algorithm>
#include <graphics.h>

// 前向声明
class Player;

// 观察者接口
class Observer {
public:
    virtual void PlayerLivesChanged(const Player& player) = 0;
    virtual void GameOver(bool isWin) = 0;
    virtual ~Observer() = default;
};

// 可观察对象接口
class Observable {
private:
    std::vector<Observer*> observers;
public:
    void AddObserver(Observer* observer);
    void RemoveObserver(Observer* observer);
    // 通知生命值变化
    void NotifyLivesChanged(const Player& player);
    // 通知游戏结束
    void NotifyGameOver(bool isWin);
};

class UIObserver : public Observer {
public:
    void PlayerLivesChanged(const Player& player) override;
    void GameOver(bool isWin) override;
};
