#pragma once
#include <vector>
#include <algorithm>
#include <graphics.h>

// 前向声明玩家类
class Player;

// 观察者接口：定义观察者需实现的回调方法
class Observer {
public:
    // 玩家生命值变化时的回调
    virtual void PlayerLivesChanged(const Player& player) = 0;
    // 游戏结束时的回调（参数表示是否胜利）
    virtual void GameOver(bool isWin) = 0;
    virtual ~Observer() = default;
};

// 可观察对象接口：管理观察者并发送通知
class Observable {
private:
    std::vector<Observer*> observers; // 观察者列表

public:
    void AddObserver(Observer* observer);    // 添加观察者
    void RemoveObserver(Observer* observer); // 移除观察者
    void NotifyLivesChanged(const Player& player); // 通知所有观察者生命值变化
    void NotifyGameOver(bool isWin);          // 通知所有观察者游戏结束
};

// UI观察者：实现UI层面的观察者逻辑
class UIObserver : public Observer {
public:
    void PlayerLivesChanged(const Player& player) override; // 更新UI显示生命值
    void GameOver(bool isWin) override;                     // 处理游戏结束的UI逻辑
};
