#include "selectmap.hpp"
#include <graphics.h>

// ��ͼѡ�������캯������ʼ�����ڴ�С��ѡ������
MapSelector::MapSelector(int width, int height)
    : _width(width), _height(height), _selectedIndex(0) {
    // ���Ĭ�ϵ�ͼѡ��
    addMapOption("�򵥵�ͼ", 15, 15);
    addMapOption("���ӵ�ͼ", 28, 28);
}

// ��ӵ�ͼѡ����ð�ťλ��
void MapSelector::addMapOption(const std::string& name, int width, int height) {
    int btnY = 100 + _mapOptions.size() * 80; // ��ťY��������������
    MapOption option{ name, width, height, _mapOptions.empty(), {100, btnY, _width - 100, btnY + 60} };
    _mapOptions.push_back(option);
}

// �жϵ��Ƿ��ھ�����
bool MapSelector::isPointInRect(int x, int y, const RECT& rect) {
    return x >= rect.left && x <= rect.right && y >= rect.top && y <= rect.bottom;
}

// ���ư�ť���������߿����֣�
void MapSelector::drawButton(const MapOption& option) {
    setfillcolor(LIGHTGRAY);
    fillrectangle(option.rect.left, option.rect.top, option.rect.right, option.rect.bottom);

    setlinecolor(BLACK);
    rectangle(option.rect.left, option.rect.top, option.rect.right, option.rect.bottom);

    settextstyle(24, 0, "SimHei");
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);

    // ���־�����ʾ
    int textX = option.rect.left + (option.rect.right - option.rect.left - textwidth(option.name.c_str())) / 2;
    int textY = option.rect.top + (option.rect.bottom - option.rect.top - textheight(option.name.c_str())) / 2;
    outtextxy(textX, textY, option.name.c_str());
}

// ��ʾѡ����棬����ѡ������
int MapSelector::show() {
    initgraph(_width, _height); // ��ʼ��ͼ�δ���
    setbkcolor(WHITE);
    cleardevice();
    BeginBatchDraw(); // ��ʼ��������

    ExMessage msg;
    bool confirmed = false;

    while (!confirmed) {
        cleardevice();

        // ���Ʊ���
        settextstyle(36, 0, "SimHei");
        settextcolor(BLACK);
        outtextxy(150, 30, "ѡ���ͼ");

        // �������е�ͼѡ�ť
        for (const auto& option : _mapOptions) {
            drawButton(option);
        }

        FlushBatchDraw(); // ˢ�»���

        // ���������Ϣ
        while (peekmessage(&msg, EX_MOUSE)) {
            if (msg.message == WM_LBUTTONDOWN) {
                // ������Ƿ��ڰ�ť��Χ��
                for (size_t i = 0; i < _mapOptions.size(); ++i) {
                    if (isPointInRect(msg.x, msg.y, _mapOptions[i].rect)) {
                        _selectedIndex = i;
                        confirmed = true; // ȷ��ѡ��
                        break;
                    }
                }
            }
        }

        Sleep(10);
    }

    EndBatchDraw(); // ������������
    closegraph(); // �ر�ͼ�δ���
    return _selectedIndex;
}

// ��ȡѡ�е�ͼ�Ŀ��
int MapSelector::getSelectedWidth() const {
    return _mapOptions[_selectedIndex].width;
}

// ��ȡѡ�е�ͼ�ĸ߶�
int MapSelector::getSelectedHeight() const {
    return _mapOptions[_selectedIndex].height;
}

// ��ȡѡ�е�ͼ������
std::string MapSelector::getSelectedName() const {
    return _mapOptions[_selectedIndex].name;
}