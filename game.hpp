#pragma once

#include "graphics.h"

class Game {
public:
    Game(int width, int height);
    ~Game();
    void run();
private:
    Map game_map;
    bool runningflag;
	void handleEvent(const ExMessage& msg);
};
