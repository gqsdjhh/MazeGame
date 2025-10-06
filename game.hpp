#pragma once

#include "graphics.h"
#include "map.hpp"
#include "player.hpp"
#include "observer.hpp"
#include "factory.hpp"  

/// 游戏主控制类，负责统筹游戏逻辑、交互及更新
class Game {
public:
    /// 构造函数，初始化游戏难度
    /// @param is_hard 是否为困难模式
    Game(bool is_hard);
    /// 析构函数，释放资源
    ~Game();

    /// 处理玩家交互输入
    void PlayerInteraction();
    /// 更新迷雾探索状态
    void UpdateFog();
    /// 启动游戏主循环
    void Run();
private:
    Factory _factory;       // 工厂类，用于创建游戏对象
    Map _game_map;          // 游戏地图数据
    Player _player;         // 玩家对象
    bool _runningflag;      // 游戏运行标志
    MapDisplay* _display;   // 地图显示组件
    UIObserver* _uiObserver;// UI观察者，处理界面反馈

    /// 处理外部事件（如用户输入）
    /// @param msg 事件消息
    void handleEvent(const ExMessage& msg);
};