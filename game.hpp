#pragma once

#include "graphics.h"
#include "map.hpp"
#include "factory.hpp"  

class Game {
public:
    Game(bool isHard = false);  // 增加难度参数
    ~Game();
    void run();
private:
    Factory factory;
    Map game_map;
    bool runningflag;
    MapDisplay* display;  // 地图显示器指针
    void handleEvent(const ExMessage& msg);
};