#include "map.hpp"

// 简单地图数据：15x15网格
// 0-墙，1-空地，2-起点，3-终点，4-陷阱
int EASY_MAP[15][15] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 4, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 4, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 3, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// 困难地图数据：28x28网格
// 0-墙，1-空地，2-起点，3-终点，4-陷阱
int HARD_MAP[28][28] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 1, 0, 0, 4, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 4, 1, 1, 0, 1, 0, 4, 0, 0, 4, 1, 0},
	{0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0},
	{0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 4, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0},
	{0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0},
	{0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 1, 0, 4, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0},
	{0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0},
	{0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0},
	{0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 1, 0, 4, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 4, 0, 1, 1, 1, 1, 1, 0, 3, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// 网格类构造函数
Grid::Grid(GridType type) : _type(type) {}

// 判断是否为可通行区域（空地/起点/终点）
bool Grid::IsRoad() const {
	return _type == GridType::EMPTY || _type == GridType::START || _type == GridType::END;
}

// 判断是否为终点
bool Grid::IsExit() const {
	return _type == GridType::END;
}

// 判断是否为陷阱
bool Grid::IsTrap() const {
	return _type == GridType::TRAP;
}

// 判断是否为墙
bool Grid::IsWall() const {
	return _type == GridType::WALL;
}

// 获取网格类型
GridType Grid::GetType() const {
	return _type;
}

// 设置网格类型
void Grid::SetType(GridType type) {
	_type = type;
}

// 判断是否已探索
bool Grid::IsExplored() const {
	return _isExplored;
}

// 设置探索状态
void Grid::SetExplored(bool is_explored) {
	_isExplored = is_explored;
}

// 地图类构造函数：初始化宽高和网格
Map::Map(int width, int height) : _width(width), _height(height) {
	map.resize(height, std::vector<Grid>(width, Grid(GridType::EMPTY)));
}

// 获取地图宽度
int Map::GetWidth() const {
	return _width;
}

// 获取地图高度
int Map::GetHeight() const {
	return _height;
}

// 获取指定坐标的网格
Grid& Map::GetMap(int x, int y) {
	return map[y][x];
}

// 设置指定坐标的网格类型
void Map::SetGridType(int x, int y, GridType type) {
	map[y][x].SetType(type);
}

// 数值转换为网格类型
GridType ToGridType(int value) {
	switch (value) {
	case 0: return GridType::WALL;    // 0->墙
	case 1: return GridType::EMPTY;   // 1->空地
	case 2: return GridType::START;   // 2->起点
	case 3: return GridType::END;     // 3->终点
	default: return GridType::TRAP;   // 其他->陷阱
	}
}

// 生成简单地图：从预设数据初始化
void EasyMapGenerator::Generate(Map& map) {
	for (size_t y = 0; y < 15; ++y) {
		for (size_t x = 0; x < 15; ++x) {
			map.SetGridType(x, y, ToGridType(EASY_MAP[y][x]));
		}
	}
}

// 生成困难地图：从预设数据初始化
void HardMapGenerator::Generate(Map& map) {
	for (size_t y = 0; y < 28; ++y) {
		for (size_t x = 0; x < 28; ++x) {
			map.SetGridType(x, y, ToGridType(HARD_MAP[y][x]));
		}
	}
}

// 显示地图：根据网格状态绘制
void EasyXMapDisplay::Display(Map& map) {
	for (size_t y = 0; y < map.GetHeight(); ++y) {
		for (size_t x = 0; x < map.GetWidth(); ++x) {
			auto& grid = map.GetMap(x, y);

			// 未探索区域显示灰色
			if (!grid.IsExplored()) {
				setfillcolor(RGB(80, 80, 80));
				fillrectangle(x * 20, y * 20, (x + 1) * 20, (y + 1) * 20);
				continue;
			}

			// 根据网格类型设置颜色
			switch (grid.GetType()) {
			case GridType::WALL:   setfillcolor(BLACK); break;  // 墙-黑色
			case GridType::TRAP:   setfillcolor(RED);   break;  // 陷阱-红色
			case GridType::END:    setfillcolor(GREEN); break;  // 终点-绿色
			default:               setfillcolor(WHITE);        // 空地/起点-白色
			}
			// 绘制网格
			fillrectangle(x * 20, y * 20, (x + 1) * 20, (y + 1) * 20);
		}
	}
}


