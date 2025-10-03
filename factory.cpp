#include "factory.hpp"
#include "map.hpp"

MapGenerator* Factory::CreateEasyMapGenerator() {
    return new EasyMapGenerator();
}

// 创建困难地图生成器
MapGenerator* Factory::CreateHardMapGenerator() {
    return new HardMapGenerator();
}

// 创建EasyX地图显示器
MapDisplay* Factory::CreateEasyXMapDisplay() {
    return new EasyXMapDisplay();
}
