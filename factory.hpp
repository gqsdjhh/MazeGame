#pragma once
#include "map.hpp"

// 工厂类，负责创建地图生成器和显示器
class Factory {
public:
    // 创建简单地图生成器
    MapGenerator* CreateEasyMapGenerator();
    // 创建困难地图生成器
    MapGenerator* CreateHardMapGenerator();
    // 创建EasyX地图显示器
    MapDisplay* CreateEasyXMapDisplay();
};