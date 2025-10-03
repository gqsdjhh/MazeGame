#pragma once
#include "map.hpp"

// �����࣬���𴴽���ͼ����������ʾ��
class Factory {
public:
    // �����򵥵�ͼ������
    MapGenerator* CreateEasyMapGenerator();
    // �������ѵ�ͼ������
    MapGenerator* CreateHardMapGenerator();
    // ����EasyX��ͼ��ʾ��
    MapDisplay* CreateEasyXMapDisplay();
};