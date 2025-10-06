#pragma once
#include <vector>
#include <algorithm>
#include <graphics.h>

// ǰ�����������
class Player;

// �۲��߽ӿڣ�����۲�����ʵ�ֵĻص�����
class Observer {
public:
    // �������ֵ�仯ʱ�Ļص�
    virtual void PlayerLivesChanged(const Player& player) = 0;
    // ��Ϸ����ʱ�Ļص���������ʾ�Ƿ�ʤ����
    virtual void GameOver(bool isWin) = 0;
    virtual ~Observer() = default;
};

// �ɹ۲����ӿڣ�����۲��߲�����֪ͨ
class Observable {
private:
    std::vector<Observer*> observers; // �۲����б�

public:
    void AddObserver(Observer* observer);    // ��ӹ۲���
    void RemoveObserver(Observer* observer); // �Ƴ��۲���
    void NotifyLivesChanged(const Player& player); // ֪ͨ���й۲�������ֵ�仯
    void NotifyGameOver(bool isWin);          // ֪ͨ���й۲�����Ϸ����
};

// UI�۲��ߣ�ʵ��UI����Ĺ۲����߼�
class UIObserver : public Observer {
public:
    void PlayerLivesChanged(const Player& player) override; // ����UI��ʾ����ֵ
    void GameOver(bool isWin) override;                     // ������Ϸ������UI�߼�
};
