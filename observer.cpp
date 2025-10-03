#include "observer.hpp"

#include <vector>

void Observable::AddObserver(Observer* observer) {
    observers.push_back(observer);
}

void Observable::RemoveObserver(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

// 通知生命值变化
void Observable::NotifyLivesChanged(const Player& player) {
    for (auto obs : observers) {
        obs->PlayerLivesChanged(player);
    }
}

// 通知游戏结束
void Observable::NotifyGameOver(bool isWin) {
    for (auto obs : observers) {
        obs->GameOver(isWin);
    }
}

void UIObserver::PlayerLivesChanged(const Player& player) {
    //// 显示剩余生命值
    //settextcolor(RED);
    //setbkmode(TRANSPARENT);
    //char text[20];
    //sprintf(text, "Lives: %d", player.GetLives());
    //outtextxy(10, 10, text);
}

void UIObserver::GameOver(bool isWin) {
    //// 显示游戏结束信息
    //settextcolor(isWin ? GREEN : RED);
    //settextstyle(24, 0, "SimHei");
    //outtextxy(100, 100, isWin ? "You Win!" : "Game Over!");
    //FlushBatchDraw();
    //Sleep(2000);  // 暂停2秒显示结果
}
