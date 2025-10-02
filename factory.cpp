#include "factory.hpp"
#include "map.hpp"

MapGenerator* Factory::createEasyMapGenerator() {
    return new EasyMapGenerator();
}

// 创建困难地图生成器
MapGenerator* Factory::createHardMapGenerator() {
    return new HardMapGenerator();
}

// 创建EasyX地图显示器
MapDisplay* Factory::createEasyXMapDisplay() {
    return new EasyXMapDisplay();
}
