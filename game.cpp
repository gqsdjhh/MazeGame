#include "game.hpp"
#include "factory.hpp"
#include "observer.hpp"
#include <utility>
#include <memory>  


// 初始化游戏环境，根据难度创建对应地图和窗口
Game::Game(bool isHard) : _game_map(10, 10), _runningflag(true), _display(nullptr) {
    std::unique_ptr<MapGenerator> generator;
    if (isHard) {
        // 困难模式：28x28地图
        generator.reset(_factory.CreateHardMapGenerator());
        initgraph(28 * 20, 28 * 20);
        _game_map = Map(28, 28);
    }
    else {
        // 简单模式：15x15地图
        generator.reset(_factory.CreateEasyMapGenerator());
        initgraph(15 * 20, 15 * 20);
        _game_map = Map(15, 15);
    }

    setbkcolor(WHITE);
    BeginBatchDraw();

    _display = _factory.CreateEasyXMapDisplay();
    generator->Generate(_game_map);
    _uiObserver = new UIObserver();
    _player.AddObserver(_uiObserver);
    UpdateFog();  // 初始化视野
}

// 清理游戏资源
Game::~Game() {
    EndBatchDraw();
    closegraph();
    delete _display;
    delete _uiObserver;
}

// 游戏主循环：处理输入、更新画面、控制帧率
void Game::Run() {
    ExMessage msg;
    while (_runningflag) {
        auto start_time = GetTickCount();

        // 处理输入事件
        while (peekmessage(&msg)) {
            handleEvent(msg);
        }

        cleardevice();
        if (_display) {
            UpdateFog();
            _display->Display(_game_map);
            _player.PlayerDisplay();
        }
        FlushBatchDraw();

        // 检查玩家存活状态
        if (!_player.IsAlive()) {
            _runningflag = false;
        }

        // 控制帧率（约60FPS）
        auto delta_time = GetTickCount() - start_time;
        if (delta_time < 16) {
            Sleep(16 - delta_time);
        }
    }
}

// 更新视野：玩家周围5x5范围标记为已探索
void Game::UpdateFog() {
    auto pos = _player.GetXY();
    const int viewRange = 5;

    for (int dy = -viewRange; dy <= viewRange; ++dy) {
        for (int dx = -viewRange; dx <= viewRange; ++dx) {
            int nx = pos.first + dx;
            int ny = pos.second + dy;

            if (nx >= 0 && nx < _game_map.GetWidth() && ny >= 0 && ny < _game_map.GetHeight()) {
                _game_map.GetMap(nx, ny).SetExplored(true);
            }
        }
    }
}

// 处理玩家与当前格子的交互（陷阱/出口）
void Game::PlayerInteraction() {
    auto pos = _player.GetXY();
    auto grid = _game_map.GetMap(pos.first, pos.second);

    if (grid.IsTrap()) {
        _player.LoseLife();  // 踩陷阱减血
        _game_map.SetGridType(pos.first, pos.second, GridType::EMPTY);
    }
    else if (grid.IsExit()) {
        _player.NotifyGameOver(true);  // 到达终点胜利
        _runningflag = false;
    }
}

// 处理用户输入：WASD移动，ESC退出
void Game::handleEvent(const ExMessage& msg) {
    if (msg.message == WM_KEYDOWN) {
        switch (msg.vkcode)
        {
        case 'W':  // 上移
            if (!_game_map.GetMap(_player.GetXY().first, _player.GetXY().second - 1).IsWall()) {
                _player.Move(0, -1);
                PlayerInteraction();
            }
            break;
        case 'S':  // 下移
            if (!_game_map.GetMap(_player.GetXY().first, _player.GetXY().second + 1).IsWall()) {
                _player.Move(0, 1);
                PlayerInteraction();
            }
            break;
        case 'A':  // 左移
            if (!_game_map.GetMap(_player.GetXY().first - 1, _player.GetXY().second).IsWall()) {
                _player.Move(-1, 0);
                PlayerInteraction();
            }
            break;
        case 'D':  // 右移
            if (!_game_map.GetMap(_player.GetXY().first + 1, _player.GetXY().second).IsWall()) {
                _player.Move(1, 0);
                PlayerInteraction();
            }
            break;
        case VK_ESCAPE:  // 退出游戏
            _runningflag = false;
            break;
        }
    }
}

