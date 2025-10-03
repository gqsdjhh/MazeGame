#include "factory.hpp"
#include "map.hpp"

MapGenerator* Factory::CreateEasyMapGenerator() {
    return new EasyMapGenerator();
}

// �������ѵ�ͼ������
MapGenerator* Factory::CreateHardMapGenerator() {
    return new HardMapGenerator();
}

// ����EasyX��ͼ��ʾ��
MapDisplay* Factory::CreateEasyXMapDisplay() {
    return new EasyXMapDisplay();
}
