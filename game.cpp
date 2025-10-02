#include "game.hpp"
#include "factory.hpp"
#include <utility>
#include <memory>  

Game::Game(bool isHard) : _game_map(10, 10), _runningflag(true), _display(nullptr) {
    std::unique_ptr<MapGenerator> generator;
    if (isHard) {
        generator.reset(_factory.createHardMapGenerator());
        initgraph(28 * 20, 28 * 20);
        _game_map = Map(28, 28);
    }
    else {
        generator.reset(_factory.createEasyMapGenerator());
		initgraph(15 * 20, 15 * 20);
        _game_map = Map(15, 15);
    }
    generator->generate(_game_map);

    setbkcolor(WHITE);
    BeginBatchDraw();

    // 使用工厂创建地图显示器
    _display = _factory.createEasyXMapDisplay();
}

Game::~Game() {
    EndBatchDraw();
    closegraph();
    delete _display;
}

void Game::run() {
    ExMessage msg;
    while (_runningflag) {
        DWORD start_time = GetTickCount();

        while (peekmessage(&msg)) {
            handleEvent(msg);
        }

        cleardevice();
        
        if (_display) {
            _display->display(_game_map);
			_player.Playerdisplay();
        }
        FlushBatchDraw();

		if (!_player.isAlive()) {
			_runningflag = false;
		}

        DWORD end_time = GetTickCount();
        DWORD delta_time = end_time - start_time;
        if (delta_time < 16) {
            Sleep(16 - delta_time);
        }
    }
}

void Game::playInteraction() {
	// 可以实现玩家与地图的交互逻辑
    auto pos = _player.getXY();
	auto grid = _game_map.getMap(pos.first, pos.second);
	if (grid.isTrap()) {
		_player.loseLife();
	}
	else if (grid.isExit()) {
		_runningflag = false; // 游戏胜利，结束游戏
	}
}

void Game::handleEvent(const ExMessage& msg) {
    if (msg.message == WM_KEYDOWN) {
		switch (msg.vkcode)
        {
        case VK_UP:
			if (!_game_map.getMap(_player.getXY().first, _player.getXY().second - 1).isWall()) {
				_player.move(0, -1);
				playInteraction();
			}
			break;
		case VK_DOWN:
			if (!_game_map.getMap(_player.getXY().first, _player.getXY().second + 1).isWall()) {
				_player.move(0, 1);
				playInteraction();
			}
			break;
		case VK_LEFT:
			if (!_game_map.getMap(_player.getXY().first - 1, _player.getXY().second).isWall()) {
				_player.move(-1, 0);
				playInteraction();
			}
			break;
		case VK_RIGHT:
			if (!_game_map.getMap(_player.getXY().first + 1, _player.getXY().second).isWall()) {
				_player.move(1, 0);
				playInteraction();
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

