#include "observer.hpp"
#include "player.hpp"

#include <vector>

// ��۲����б���ӹ۲���
void Observable::AddObserver(Observer* observer) {
    observers.push_back(observer);
}

// �ӹ۲����б��Ƴ�ָ���۲���
void Observable::RemoveObserver(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

// ֪ͨ���й۲����������ֵ�仯
void Observable::NotifyLivesChanged(const Player& player) {
    for (auto obs : observers) {
        obs->PlayerLivesChanged(player);
    }
}

// ֪ͨ���й۲�����Ϸ����
void Observable::NotifyGameOver(bool isWin) {
    for (auto obs : observers) {
        obs->GameOver(isWin);
    }
}

// ʵ���������ֵ�仯ʱ��UI����
void UIObserver::PlayerLivesChanged(const Player& player) {
    // ��ʾʣ������ֵ
    settextcolor(RED);
    settextstyle(24, 0, "SimHei");
    setbkmode(TRANSPARENT);
    char text[20];
    _stprintf_s(text, "Lives: %d", player.GetLives());
    outtextxy(100, 100, text);
    FlushBatchDraw();
    Sleep(1000);
}

// ʵ����Ϸ����ʱ��UI��ʾ
void UIObserver::GameOver(bool isWin) {
    // ��ʾ��Ϸ�����Ϣ
    settextcolor(isWin ? GREEN : RED);
    settextstyle(24, 0, "SimHei");
    outtextxy(100, 100, isWin ? "You Win!" : "Game Over!");
    FlushBatchDraw();
    Sleep(2000);  // ��ͣ2����ʾ���
}
