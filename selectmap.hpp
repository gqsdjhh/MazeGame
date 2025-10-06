#pragma once
#include <graphics.h>
#include <string>
#include <vector>

// ��ͼѡ��ṹ�壬�洢��ͼ��Ϣ
struct MapOption {
    std::string name;       // ��ͼ����
    int width;              // ��ͼ���
    int height;             // ��ͼ�߶�
    bool isSelected;        // ѡ��״̬��ʶ����Ȼ��ɫ���䵫�Կɱ��������ڲ��߼���
    RECT rect;              // ��ť�������
};

// ��ͼѡ�����࣬�����ͼѡ��������ʾ�ͽ���
class MapSelector {
private:
    int _width;             // ѡ�������
    int _height;            // ѡ�����߶�
    std::vector<MapOption> _mapOptions;  // ��ͼѡ���б�
    int _selectedIndex;     // ��ǰѡ�еĵ�ͼ����

    // �жϵ��Ƿ��ھ���������
    bool isPointInRect(int x, int y, const RECT& rect);
    // ���Ƶ�����ť
    void drawButton(const MapOption& option);

public:
    // ���캯������ʼ������ߴ��Ĭ��ѡ��
    MapSelector(int width = 600, int height = 400);
    // ��ӵ�ͼѡ��
    void addMapOption(const std::string& name, int width, int height);
    // ��ʾѡ����沢����ѡ�е�����
    int show();
    // ��ȡѡ�е�ͼ�Ŀ��
    int getSelectedWidth() const;
    // ��ȡѡ�е�ͼ�ĸ߶�
    int getSelectedHeight() const;
    // ��ȡѡ�е�ͼ������
    std::string getSelectedName() const;
};

