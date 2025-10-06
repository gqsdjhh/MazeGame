#pragma once

#include "graphics.h"
#include "map.hpp"
#include "player.hpp"
#include "observer.hpp"
#include "factory.hpp"  

/// ��Ϸ�������࣬����ͳ����Ϸ�߼�������������
class Game {
public:
    /// ���캯������ʼ����Ϸ�Ѷ�
    /// @param is_hard �Ƿ�Ϊ����ģʽ
    Game(bool is_hard);
    /// �����������ͷ���Դ
    ~Game();

    /// ������ҽ�������
    void PlayerInteraction();
    /// ��������̽��״̬
    void UpdateFog();
    /// ������Ϸ��ѭ��
    void Run();
private:
    Factory _factory;       // �����࣬���ڴ�����Ϸ����
    Map _game_map;          // ��Ϸ��ͼ����
    Player _player;         // ��Ҷ���
    bool _runningflag;      // ��Ϸ���б�־
    MapDisplay* _display;   // ��ͼ��ʾ���
    UIObserver* _uiObserver;// UI�۲��ߣ�������淴��

    /// �����ⲿ�¼������û����룩
    /// @param msg �¼���Ϣ
    void handleEvent(const ExMessage& msg);
};