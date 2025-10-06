#include "observer.hpp"
#include "player.hpp"

#include <vector>

// 向观察者列表添加观察者
void Observable::AddObserver(Observer* observer) {
    observers.push_back(observer);
}

// 从观察者列表移除指定观察者
void Observable::RemoveObserver(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

// 通知所有观察者玩家生命值变化
void Observable::NotifyLivesChanged(const Player& player) {
    for (auto obs : observers) {
        obs->PlayerLivesChanged(player);
    }
}

// 通知所有观察者游戏结束
void Observable::NotifyGameOver(bool isWin) {
    for (auto obs : observers) {
        obs->GameOver(isWin);
    }
}

// 实现玩家生命值变化时的UI更新
void UIObserver::PlayerLivesChanged(const Player& player) {
    // 显示剩余生命值
    settextcolor(RED);
    settextstyle(24, 0, "SimHei");
    setbkmode(TRANSPARENT);
    char text[20];
    _stprintf_s(text, "Lives: %d", player.GetLives());
    outtextxy(100, 100, text);
    FlushBatchDraw();
    Sleep(1000);
}

// 实现游戏结束时的UI提示
void UIObserver::GameOver(bool isWin) {
    // 显示游戏结果信息
    settextcolor(isWin ? GREEN : RED);
    settextstyle(24, 0, "SimHei");
    outtextxy(100, 100, isWin ? "You Win!" : "Game Over!");
    FlushBatchDraw();
    Sleep(2000);  // 暂停2秒显示结果
}
