#pragma once

#include "graphics.h"
#include <vector>

// 网格类型枚举
enum class GridType {
	EMPTY = 0,      // 空地
	WALL,           // 墙壁
	START,          // 起点
	END,            // 终点
	TRAP            // 陷阱
};

// 网格单元类
class Grid {
public:
	Grid(GridType type);       // 构造函数，初始化网格类型
	bool IsRoad() const;       // 判断是否为可通行区域（空地/起点/终点）
	bool IsExit() const;       // 判断是否为终点
	bool IsTrap() const;       // 判断是否为陷阱
	bool IsWall() const;       // 判断是否为墙壁
	GridType GetType() const;  // 获取网格类型
	void SetType(GridType type); // 设置网格类型
	bool IsExplored() const;   // 判断是否已探索
	void SetExplored(bool is_explored); // 设置探索状态

private:
	GridType _type;        // 网格类型
	bool _isExplored;      // 探索状态标记
};

// 地图类
class Map {
public:
	Map(int width, int height); // 构造函数，初始化地图尺寸
	~Map() = default;

	int GetWidth() const;       // 获取地图宽度
	int GetHeight() const;      // 获取地图高度
	Grid& GetMap(int x, int y); // 获取指定坐标的网格
	void SetGridType(int x, int y, GridType type); // 设置指定坐标的网格类型

private:
	int _width;                   // 地图宽度
	int _height;                  // 地图高度
	std::vector<std::vector<Grid>> map; // 网格二维数组
};

// 地图生成器基类
class MapGenerator {
public:
	virtual void Generate(Map& map) = 0; // 生成地图（纯虚函数）
	virtual ~MapGenerator() = default;
};

// 简单地图生成器
class EasyMapGenerator : public MapGenerator {
public:
	void Generate(Map& map) override; // 生成简单难度地图
};

// 困难地图生成器
class HardMapGenerator : public MapGenerator {
public:
	void Generate(Map& map) override; // 生成困难难度地图
};

// 地图显示器基类
class MapDisplay {
public:
	virtual void Display(Map& map) = 0; // 显示地图（纯虚函数）
};

// EasyX库地图显示器
class EasyXMapDisplay : public MapDisplay {
public:
	void Display(Map& map) override; // 使用EasyX库显示地图
};