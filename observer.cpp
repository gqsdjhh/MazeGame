#include "observer.hpp"

#include <vector>

void Observable::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Observable::removeObserver(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

// ֪ͨ����ֵ�仯
void Observable::notifyLivesChanged(const Player& player) {
    for (auto obs : observers) {
        obs->onPlayerLivesChanged(player);
    }
}

// ֪ͨ��Ϸ����
void Observable::notifyGameOver(bool isWin) {
    for (auto obs : observers) {
        obs->onGameOver(isWin);
    }
}

void UIObserver::onPlayerLivesChanged(const Player& player) {
    //// ��ʾʣ������ֵ
    //settextcolor(RED);
    //setbkmode(TRANSPARENT);
    //char text[20];
    //sprintf(text, "Lives: %d", player.getLives());
    //outtextxy(10, 10, text);
}

void UIObserver::onGameOver(bool isWin) {
    //// ��ʾ��Ϸ������Ϣ
    //settextcolor(isWin ? GREEN : RED);
    //settextstyle(24, 0, "SimHei");
    //outtextxy(100, 100, isWin ? "You Win!" : "Game Over!");
    //FlushBatchDraw();
    //Sleep(2000);  // ��ͣ2����ʾ���
}
