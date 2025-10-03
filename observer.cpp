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

// ֪ͨ����ֵ�仯
void Observable::NotifyLivesChanged(const Player& player) {
    for (auto obs : observers) {
        obs->PlayerLivesChanged(player);
    }
}

// ֪ͨ��Ϸ����
void Observable::NotifyGameOver(bool isWin) {
    for (auto obs : observers) {
        obs->GameOver(isWin);
    }
}

void UIObserver::PlayerLivesChanged(const Player& player) {
    //// ��ʾʣ������ֵ
    //settextcolor(RED);
    //setbkmode(TRANSPARENT);
    //char text[20];
    //sprintf(text, "Lives: %d", player.GetLives());
    //outtextxy(10, 10, text);
}

void UIObserver::GameOver(bool isWin) {
    //// ��ʾ��Ϸ������Ϣ
    //settextcolor(isWin ? GREEN : RED);
    //settextstyle(24, 0, "SimHei");
    //outtextxy(100, 100, isWin ? "You Win!" : "Game Over!");
    //FlushBatchDraw();
    //Sleep(2000);  // ��ͣ2����ʾ���
}
