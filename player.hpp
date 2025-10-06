#pragma once
#include <utility>
#include "observer.hpp"  // �۲���ģʽ�ӿ�

// ����࣬�̳пɹ۲�ӿڣ��۲���ģʽ��
class Player : public Observable {
public:
    // ���캯������ʼ����ʼ����(Ĭ��(1,1))
    Player(int startX = 1, int startY = 1);
    // ��ȡ��ǰ����
    std::pair<int, int> GetXY() const;

    // �ƶ����(dx/dyΪ����仯��)
    void Move(int dx, int dy);
    // ��ȡʣ��������
    int GetLives() const;
    // ����һ������
    void LoseLife();
    // �ж��Ƿ���
    bool IsAlive();
    // ��ʾ�����Ϣ
    void PlayerDisplay() const;
    // Ĭ����������
    ~Player() = default;

private:
    int _x;      // x����
    int _y;      // y����
    int _lives;  // ������
};
