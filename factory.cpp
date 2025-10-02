#include "factory.hpp"
#include "map.hpp"

MapGenerator* Factory::createEasyMapGenerator() {
    return new EasyMapGenerator();
}

// �������ѵ�ͼ������
MapGenerator* Factory::createHardMapGenerator() {
    return new HardMapGenerator();
}

// ����EasyX��ͼ��ʾ��
MapDisplay* Factory::createEasyXMapDisplay() {
    return new EasyXMapDisplay();
}
