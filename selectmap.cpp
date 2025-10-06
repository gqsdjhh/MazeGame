#include "selectmap.hpp"
#include <graphics.h>

MapSelector::MapSelector(int width, int height)
    : _width(width), _height(height), _selectedIndex(0) {
    // 初始化默认的地图选项
    addMapOption("简单地图", 15, 15);
    addMapOption("困难地图", 28, 28);
}

void MapSelector::addMapOption(const std::string& name, int width, int height) {
    int btnY = 100 + _mapOptions.size() * 80;
    MapOption option{name, width, height, _mapOptions.empty(), {100, btnY, _width - 100, btnY + 60}};
    _mapOptions.push_back(option);
}

bool MapSelector::isPointInRect(int x, int y, const RECT& rect) {
    return x >= rect.left && x <= rect.right && y >= rect.top && y <= rect.bottom;
}

void MapSelector::drawButton(const MapOption& option) {
    setfillcolor(LIGHTGRAY);
    fillrectangle(option.rect.left, option.rect.top, option.rect.right, option.rect.bottom);

    // 绘制按钮边框
    setlinecolor(BLACK);
    rectangle(option.rect.left, option.rect.top, option.rect.right, option.rect.bottom);

    // 绘制按钮文字
    settextstyle(24, 0, "SimHei");
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);

    // 计算文字位置，居中显示
    int textX = option.rect.left + (option.rect.right - option.rect.left - textwidth(option.name.c_str())) / 2;
    int textY = option.rect.top + (option.rect.bottom - option.rect.top - textheight(option.name.c_str())) / 2;
    outtextxy(textX, textY, option.name.c_str());
}

int MapSelector::show() {
    initgraph(_width, _height);
    setbkcolor(WHITE);
    cleardevice();
    BeginBatchDraw();

    ExMessage msg;
    bool confirmed = false;

    while (!confirmed) {
        cleardevice();

        // 绘制标题
        settextstyle(36, 0, "SimHei");
        settextcolor(BLACK);
        outtextxy(150, 30, "选择地图");

        // 绘制所有的地图选项
        for (const auto& option : _mapOptions) {
            drawButton(option);
        }

        FlushBatchDraw();

        while (peekmessage(&msg, EX_MOUSE)) {
            if (msg.message == WM_LBUTTONDOWN) {
                // 处理鼠标点击
                for (size_t i = 0; i < _mapOptions.size(); ++i) {
                    if (isPointInRect(msg.x, msg.y, _mapOptions[i].rect)) {
                        _selectedIndex = i;
                        confirmed = true;  // 点击即确认选择
                        break;
                    }
                }
            }
        }

        Sleep(10);
    }

    EndBatchDraw();
    closegraph();
    return _selectedIndex;
}

int MapSelector::getSelectedWidth() const {
    return _mapOptions[_selectedIndex].width;
}

int MapSelector::getSelectedHeight() const {
    return _mapOptions[_selectedIndex].height;
}

std::string MapSelector::getSelectedName() const {
    return _mapOptions[_selectedIndex].name;
}
