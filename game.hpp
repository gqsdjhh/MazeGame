#pragma once

#include "graphics.h"
#include "map.hpp"
#include "factory.hpp"  

class Game {
public:
    Game(bool isHard = false);  // �����ѶȲ���
    ~Game();
    void run();
private:
    Factory factory;
    Map game_map;
    bool runningflag;
    MapDisplay* display;  // ��ͼ��ʾ��ָ��
    void handleEvent(const ExMessage& msg);
};