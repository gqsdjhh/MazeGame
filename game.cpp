#include "game.hpp"
#include "factory.hpp"
#include <memory>  

Game::Game(bool isHard) : game_map(10, 10), runningflag(true), display(nullptr) {
    // 使用工厂创建地图生成器
    std::unique_ptr<MapGenerator> generator;
    if (isHard) {
        generator.reset(factory.createHardMapGenerator());
        initgraph(28 * 20, 28 * 20);
		game_map = Map(28, 28);
    }
    else {
        generator.reset(factory.createEasyMapGenerator());
		initgraph(15 * 20, 15 * 20);
		game_map = Map(15, 15);
    }
    generator->generate(game_map);

    setbkcolor(WHITE);
    BeginBatchDraw();

    // 使用工厂创建地图显示器
    display = factory.createEasyXMapDisplay();
}

Game::~Game() {
    EndBatchDraw();
    closegraph();
    delete display;
}

void Game::run() {
    ExMessage msg;
    while (runningflag) {
        DWORD start_time = GetTickCount();

        while (peekmessage(&msg)) {
            handleEvent(msg);
        }

        cleardevice();
        
        if (display) {
            display->display(game_map);
        }
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
        // 保留原有逻辑
    }
    // 保留原有逻辑
}

