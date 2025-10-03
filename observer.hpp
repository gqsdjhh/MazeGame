#pragma once
#include <vector>
#include <algorithm>
#include <graphics.h>

// ǰ������
class Player;

// �۲��߽ӿ�
class Observer {
public:
    virtual void onPlayerLivesChanged(const Player& player) = 0;
    virtual void onGameOver(bool isWin) = 0;
    virtual ~Observer() = default;
};

// �ɹ۲����ӿ�
class Observable {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    // ֪ͨ����ֵ�仯
    void notifyLivesChanged(const Player& player);
    // ֪ͨ��Ϸ����
    void notifyGameOver(bool isWin);
};

class UIObserver : public Observer {
public:
    void onPlayerLivesChanged(const Player& player) override;
    void onGameOver(bool isWin) override;
};
