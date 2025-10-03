#pragma once
#include <vector>
#include <algorithm>
#include <graphics.h>

// ǰ������
class Player;

// �۲��߽ӿ�
class Observer {
public:
    virtual void PlayerLivesChanged(const Player& player) = 0;
    virtual void GameOver(bool isWin) = 0;
    virtual ~Observer() = default;
};

// �ɹ۲����ӿ�
class Observable {
private:
    std::vector<Observer*> observers;
public:
    void AddObserver(Observer* observer);
    void RemoveObserver(Observer* observer);
    // ֪ͨ����ֵ�仯
    void NotifyLivesChanged(const Player& player);
    // ֪ͨ��Ϸ����
    void NotifyGameOver(bool isWin);
};

class UIObserver : public Observer {
public:
    void PlayerLivesChanged(const Player& player) override;
    void GameOver(bool isWin) override;
};
