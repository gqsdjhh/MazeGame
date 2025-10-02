#pragma once

#include "graphics.h"
#include "map.hpp"
#include "player.hpp"
#include "factory.hpp"  

class Game {
public:
    Game(bool isHard = false);  // 增加难度参数
    ~Game();
	void playInteraction();
    void run();
private:
    Factory _factory;
    Map _game_map;
	Player _player;
    bool _runningflag;
    MapDisplay* _display;  // 地图显示器指针
    void handleEvent(const ExMessage& msg);
};