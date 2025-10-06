#include "game.hpp"
#include "factory.hpp"
#include "observer.hpp"
#include <utility>
#include <memory>  

Game::Game(bool isHard) : _game_map(10, 10), _runningflag(true), _display(nullptr) {
    std::unique_ptr<MapGenerator> generator;
    if (isHard) {
        generator.reset(_factory.CreateHardMapGenerator());
        initgraph(28 * 20, 28 * 20);
        _game_map = Map(28, 28);
    }
    else {
        generator.reset(_factory.CreateEasyMapGenerator());
		initgraph(15 * 20, 15 * 20);
        _game_map = Map(15, 15);
    }

    setbkcolor(WHITE);
    BeginBatchDraw();

    // 使用工厂创建地图显示器
    _display = _factory.CreateEasyXMapDisplay();
    generator->Generate(_game_map);
    _uiObserver = new UIObserver();
    _player.AddObserver(_uiObserver);
    UpdateFog();
}

Game::~Game() {
    EndBatchDraw();
    closegraph();
    delete _display;
    delete _uiObserver;
}

void Game::Run() {
    ExMessage msg;
    while (_runningflag) {
        auto start_time = GetTickCount();

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

		if (!_player.IsAlive()) {
			_runningflag = false;
		}

        auto end_time = GetTickCount();
        auto delta_time = end_time - start_time;
        if (delta_time < 16) {
            Sleep(16 - delta_time);
        }
    }
}

void Game::UpdateFog() {
    auto pos = _player.GetXY();
    const int viewRange = 5;  // 5x5范围（中心向外2格）

    // 遍历5x5区域，标记为已探索
    for (int dy = -viewRange; dy <= viewRange; ++dy) {
        for (int dx = -viewRange; dx <= viewRange; ++dx) {
            int nx = pos.first + dx;
            int ny = pos.second + dy;

            // 检查坐标是否在地图范围内
            if (nx >= 0 && nx < _game_map.GetWidth() && ny >= 0 && ny < _game_map.GetHeight()) {
                // 直接修改格子的探索状态
                _game_map.GetMap(nx, ny).SetExplored(true);
            }
        }
    }
}

void Game::PlayerInteraction() {
	auto pos = _player.GetXY();
	auto grid = _game_map.GetMap(pos.first, pos.second);
	if (grid.IsTrap()) {
		_player.LoseLife();  // 玩家生命值减少
        _game_map.SetGridType(pos.first, pos.second, GridType::EMPTY);
	}
	else if (grid.IsExit()) {
		_player.NotifyGameOver(true);  // 通知游戏胜利
		_runningflag = false;
	}
}

void Game::handleEvent(const ExMessage& msg) {
    if (msg.message == WM_KEYDOWN) {
        switch (msg.vkcode)
        {
        case 'W':
            if (!_game_map.GetMap(_player.GetXY().first, _player.GetXY().second - 1).IsWall()) {
                _player.Move(0, -1);
                PlayerInteraction();
            }
            break;
        case 'S':
            if (!_game_map.GetMap(_player.GetXY().first, _player.GetXY().second + 1).IsWall()) {
                _player.Move(0, 1);
                PlayerInteraction();
            }
            break;
        case 'A':
            if (!_game_map.GetMap(_player.GetXY().first - 1, _player.GetXY().second).IsWall()) {
                _player.Move(-1, 0);
                PlayerInteraction();
            }
            break;
        case 'D':
            if (!_game_map.GetMap(_player.GetXY().first + 1, _player.GetXY().second).IsWall()) {
                _player.Move(1, 0);
                PlayerInteraction();
            }
            break;
        case VK_ESCAPE:
            _runningflag = false; // 按下ESC键退出游戏
            break;
        default:
            break;
        }
    }
}

