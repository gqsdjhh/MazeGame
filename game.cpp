#include "graphics.h"

#include "game.hpp"
#include "factory.hpp"


Game::Game(int width, int height) : game_map(width, height), runningflag(true) {
    initgraph(width * 20, height * 20);
    setbkcolor(WHITE);
    game_map.generate();
    BeginBatchDraw();
}

Game::~Game() {
    EndBatchDraw();
    closegraph();
}

void Game::run() {
    ExMessage msg;
    while (runningflag) {
        DWORD start_time = GetTickCount();

        while (peekmessage(&msg)) {
            handleEvent(msg);
        }

        cleardevice();
        game_map.display();
        FlushBatchDraw();

        DWORD end_time = GetTickCount();
        DWORD delta_time = end_time - start_time;
        if (delta_time < 16) {
            Sleep(16 - delta_time);
        }
    }
}

void Game::handleEvent(const ExMessage& msg) {
    if (msg.message == WM_LBUTTONDOWN) {
        int index_x = msg.x / 20;
        int index_y = msg.y / 20;
        // 这里可以扩展为地图交互等
    }
    // 可以扩展更多事件
}

