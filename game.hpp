#pragma once

#include "graphics.h"
#include "map.hpp"
#include "player.hpp"
#include "observer.hpp"
#include "factory.hpp"  

class Game {
public:
    Game(bool is_hard = false);  
    ~Game();
	void PlayerInteraction();
    void Run();
private:
    Factory _factory;
    Map _game_map;
	Player _player;
    bool _runningflag;
    MapDisplay* _display;  
    UIObserver* _uiObserver;
    void handleEvent(const ExMessage& msg);
};