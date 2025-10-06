#include "game.hpp"
#include "factory.hpp"
#include "observer.hpp"
#include <utility>
#include <memory>  


// ��ʼ����Ϸ�����������Ѷȴ�����Ӧ��ͼ�ʹ���
Game::Game(bool isHard) : _game_map(10, 10), _runningflag(true), _display(nullptr) {
    std::unique_ptr<MapGenerator> generator;
    if (isHard) {
        // ����ģʽ��28x28��ͼ
        generator.reset(_factory.CreateHardMapGenerator());
        initgraph(28 * 20, 28 * 20);
        _game_map = Map(28, 28);
    }
    else {
        // ��ģʽ��15x15��ͼ
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
    UpdateFog();  // ��ʼ����Ұ
}

// ������Ϸ��Դ
Game::~Game() {
    EndBatchDraw();
    closegraph();
    delete _display;
    delete _uiObserver;
}

// ��Ϸ��ѭ�����������롢���»��桢����֡��
void Game::Run() {
    ExMessage msg;
    while (_runningflag) {
        auto start_time = GetTickCount();

        // ���������¼�
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

        // �����Ҵ��״̬
        if (!_player.IsAlive()) {
            _runningflag = false;
        }

        // ����֡�ʣ�Լ60FPS��
        auto delta_time = GetTickCount() - start_time;
        if (delta_time < 16) {
            Sleep(16 - delta_time);
        }
    }
}

// ������Ұ�������Χ5x5��Χ���Ϊ��̽��
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

// ��������뵱ǰ���ӵĽ���������/���ڣ�
void Game::PlayerInteraction() {
    auto pos = _player.GetXY();
    auto grid = _game_map.GetMap(pos.first, pos.second);

    if (grid.IsTrap()) {
        _player.LoseLife();  // �������Ѫ
        _game_map.SetGridType(pos.first, pos.second, GridType::EMPTY);
    }
    else if (grid.IsExit()) {
        _player.NotifyGameOver(true);  // �����յ�ʤ��
        _runningflag = false;
    }
}

// �����û����룺WASD�ƶ���ESC�˳�
void Game::handleEvent(const ExMessage& msg) {
    if (msg.message == WM_KEYDOWN) {
        switch (msg.vkcode)
        {
        case 'W':  // ����
            if (!_game_map.GetMap(_player.GetXY().first, _player.GetXY().second - 1).IsWall()) {
                _player.Move(0, -1);
                PlayerInteraction();
            }
            break;
        case 'S':  // ����
            if (!_game_map.GetMap(_player.GetXY().first, _player.GetXY().second + 1).IsWall()) {
                _player.Move(0, 1);
                PlayerInteraction();
            }
            break;
        case 'A':  // ����
            if (!_game_map.GetMap(_player.GetXY().first - 1, _player.GetXY().second).IsWall()) {
                _player.Move(-1, 0);
                PlayerInteraction();
            }
            break;
        case 'D':  // ����
            if (!_game_map.GetMap(_player.GetXY().first + 1, _player.GetXY().second).IsWall()) {
                _player.Move(1, 0);
                PlayerInteraction();
            }
            break;
        case VK_ESCAPE:  // �˳���Ϸ
            _runningflag = false;
            break;
        }
    }
}

