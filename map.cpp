#include "map.hpp"

int EASY_MAP[15][15] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
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

int HARD_MAP[28][28] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0},
	{0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0},
	{0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0},
	{0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0},
	{0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0},
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
	{0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 3, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

Grid::Grid(GridType type) : _type(type) {}

bool Grid::IsRoad() const {
	return _type == GridType::EMPTY || _type == GridType::START || _type == GridType::END;
}

bool Grid::IsExit() const {
	return _type == GridType::END;
}

bool Grid::IsTrap() const {
	return _type == GridType::TRAP;
}

bool Grid::IsWall() const {
	return _type == GridType::WALL;
}

GridType Grid::GetType() const {
	return _type;
}

void Grid::SetType(GridType type) {
	_type = type;
}

bool Grid::IsExplored() const {
	return _isExplored;
}

void Grid::SetExplored(bool is_explored) {
	_isExplored = is_explored;
}

Map::Map(int width, int height) : _width(width), _height(height) {
	map.resize(height, std::vector<Grid>(width, Grid(GridType::EMPTY)));
}

int Map::GetWidth() const {
	return _width;
}

int Map::GetHeight() const {
	return _height;
}

Grid& Map::GetMap(int x, int y){
	return map[y][x];
}

void Map::SetGridType(int x, int y, GridType type) {
		map[y][x].SetType(type);
}

GridType ToGridType(int value) {
	switch (value) {
		case 0: return GridType::WALL;
		case 1: return GridType::EMPTY;
		case 2: return GridType::START;
		case 3: return GridType::END;
		default: return GridType::TRAP;
	}
}

void EasyMapGenerator::Generate(Map& map) {
	// 遍历预设地图数据，设置对应格子类型
	for (size_t y = 0; y < 15; ++y) {
		for (size_t x = 0; x < 15; ++x) {
			map.SetGridType(x, y, ToGridType(EASY_MAP[y][x]));
		}
	}
}

void HardMapGenerator::Generate(Map& map) {
	// 遍历预设地图数据，设置对应格子类型
	for (size_t y = 0; y < 28; ++y) {
		for (size_t x = 0; x < 28; ++x) {
			map.SetGridType(x, y, ToGridType(HARD_MAP[y][x]));
		}
	}
}

void EasyXMapDisplay::Display(Map& map){
	for (size_t y = 0; y < map.GetHeight(); ++y) {
		for (size_t x = 0; x < map.GetWidth(); ++x) {
			auto temp = map.GetMap(x, y);

			if (!temp.IsExplored()) {
				setfillcolor(RGB(80, 80, 80));  // 灰色迷雾
				fillrectangle(20, 20, 20, 20);
				continue;
			}

			switch (temp.GetType()) {
			case GridType::WALL:
				setfillcolor(BLACK);
				break;
			case GridType::TRAP:
				setfillcolor(RED);
				break;
			case GridType::END:
				setfillcolor(GREEN);
				break;
			case GridType::EMPTY:
				setfillcolor(WHITE);
				break;
			default:
				setfillcolor(WHITE);
				break;
			}
			fillrectangle(x * 20, y * 20, (x + 1) * 20, (y + 1) * 20);
		}
	}
}

//// EasyXMapDisplay::DrawMap 方法中
//void EasyXMapDisplay::DrawMap(const Map& map) {
//	int gridSize = 30;
//	for (int y = 0; y < map.GetHeight(); ++y) {
//		for (int x = 0; x < map.GetWidth(); ++x) {
//			int screenX = x * gridSize;
//			int screenY = y * gridSize;
//			const Grid& grid = map.GetMap(x, y);
//
//			// 未探索区域：绘制迷雾
//			
//
//			// 已探索区域：正常绘制地形
//			switch (grid.GetType()) {
//			case GridType::WALL:    setfillcolor(BLACK); break;
//			case GridType::TRAP:    setfillcolor(RED); break;
//			case GridType::EXIT:    setfillcolor(GREEN); break;
//			case GridType::START:   setfillcolor(YELLOW); break;
//			default:                setfillcolor(WHITE);  // 空地
//			}
//			fillrectangle(screenX, screenY, screenX + gridSize, screenY + gridSize);
//		}
//	}
//}



