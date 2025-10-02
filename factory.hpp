#pragma once
#include "map.hpp"

// �����࣬���𴴽���ͼ����������ʾ��
class Factory {
public:
    // �����򵥵�ͼ������
    MapGenerator* createEasyMapGenerator();
    // �������ѵ�ͼ������
    MapGenerator* createHardMapGenerator();
    // ����EasyX��ͼ��ʾ��
    MapDisplay* createEasyXMapDisplay();
};