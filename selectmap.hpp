#pragma once
#include <graphics.h>
#include <string>
#include <vector>

// 地图选项结构体，存储地图信息
struct MapOption {
    std::string name;       // 地图名称
    int width;              // 地图宽度
    int height;             // 地图高度
    bool isSelected;        // 选中状态标识（虽然颜色不变但仍可保留用于内部逻辑）
    RECT rect;              // 按钮区域矩形
};

// 地图选择器类，负责地图选择界面的显示和交互
class MapSelector {
private:
    int _width;             // 选择界面宽度
    int _height;            // 选择界面高度
    std::vector<MapOption> _mapOptions;  // 地图选项列表
    int _selectedIndex;     // 当前选中的地图索引

    // 判断点是否在矩形区域内
    bool isPointInRect(int x, int y, const RECT& rect);
    // 绘制单个按钮
    void drawButton(const MapOption& option);

public:
    // 构造函数，初始化界面尺寸和默认选项
    MapSelector(int width = 600, int height = 400);
    // 添加地图选项
    void addMapOption(const std::string& name, int width, int height);
    // 显示选择界面并返回选中的索引
    int show();
    // 获取选中地图的宽度
    int getSelectedWidth() const;
    // 获取选中地图的高度
    int getSelectedHeight() const;
    // 获取选中地图的名称
    std::string getSelectedName() const;
};

