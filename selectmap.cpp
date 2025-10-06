#include "selectmap.hpp"
#include <graphics.h>

// 地图选择器构造函数，初始化窗口大小和选中索引
MapSelector::MapSelector(int width, int height)
    : _width(width), _height(height), _selectedIndex(0) {
    // 添加默认地图选项
    addMapOption("简单地图", 15, 15);
    addMapOption("复杂地图", 28, 28);
}

// 添加地图选项，设置按钮位置
void MapSelector::addMapOption(const std::string& name, int width, int height) {
    int btnY = 100 + _mapOptions.size() * 80; // 按钮Y坐标随数量递增
    MapOption option{ name, width, height, _mapOptions.empty(), {100, btnY, _width - 100, btnY + 60} };
    _mapOptions.push_back(option);
}

// 判断点是否在矩形内
bool MapSelector::isPointInRect(int x, int y, const RECT& rect) {
    return x >= rect.left && x <= rect.right && y >= rect.top && y <= rect.bottom;
}

// 绘制按钮（背景、边框、文字）
void MapSelector::drawButton(const MapOption& option) {
    setfillcolor(LIGHTGRAY);
    fillrectangle(option.rect.left, option.rect.top, option.rect.right, option.rect.bottom);

    setlinecolor(BLACK);
    rectangle(option.rect.left, option.rect.top, option.rect.right, option.rect.bottom);

    settextstyle(24, 0, "SimHei");
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);

    // 文字居中显示
    int textX = option.rect.left + (option.rect.right - option.rect.left - textwidth(option.name.c_str())) / 2;
    int textY = option.rect.top + (option.rect.bottom - option.rect.top - textheight(option.name.c_str())) / 2;
    outtextxy(textX, textY, option.name.c_str());
}

// 显示选择界面，返回选中索引
int MapSelector::show() {
    initgraph(_width, _height); // 初始化图形窗口
    setbkcolor(WHITE);
    cleardevice();
    BeginBatchDraw(); // 开始批量绘制

    ExMessage msg;
    bool confirmed = false;

    while (!confirmed) {
        cleardevice();

        // 绘制标题
        settextstyle(36, 0, "SimHei");
        settextcolor(BLACK);
        outtextxy(150, 30, "选择地图");

        // 绘制所有地图选项按钮
        for (const auto& option : _mapOptions) {
            drawButton(option);
        }

        FlushBatchDraw(); // 刷新绘制

        // 处理鼠标消息
        while (peekmessage(&msg, EX_MOUSE)) {
            if (msg.message == WM_LBUTTONDOWN) {
                // 检查点击是否在按钮范围内
                for (size_t i = 0; i < _mapOptions.size(); ++i) {
                    if (isPointInRect(msg.x, msg.y, _mapOptions[i].rect)) {
                        _selectedIndex = i;
                        confirmed = true; // 确认选择
                        break;
                    }
                }
            }
        }

        Sleep(10);
    }

    EndBatchDraw(); // 结束批量绘制
    closegraph(); // 关闭图形窗口
    return _selectedIndex;
}

// 获取选中地图的宽度
int MapSelector::getSelectedWidth() const {
    return _mapOptions[_selectedIndex].width;
}

// 获取选中地图的高度
int MapSelector::getSelectedHeight() const {
    return _mapOptions[_selectedIndex].height;
}

// 获取选中地图的名称
std::string MapSelector::getSelectedName() const {
    return _mapOptions[_selectedIndex].name;
}