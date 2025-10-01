#include "map.hpp"

Grid::Grid(GridType type) : _type(type) {}

bool Grid::isRoad() const {
	return _type == GridType::EMPTY || _type == GridType::START || _type == GridType::END;
}

bool Grid::isExit() const {
	return _type == GridType::END;
}

bool Grid::isTrap() const {
	return _type == GridType::TRAP;
}

bool Grid::isWall() const {
	return _type == GridType::WALL;
}

GridType Grid::getType() const {
	return _type;
}

void Grid::setType(GridType type) {
	_type = type;
}

Map::Map(int width, int height) : _width(width), _height(height) {
	map.resize(height, std::vector<Grid>(width, Grid(GridType::EMPTY)));
}

Map::~Map() {}

void Map::generate() {
	// 初始化地图，全部设为墙壁
	for (int y = 0; y < _height; ++y) {
		for (int x = 0; x < _width; ++x) {
			map[y][x].setType(GridType::EMPTY);
		}
	}
}

void Map::display() const {
	for (int y = 0; y < _height; ++y) {
		for (int x = 0; x < _width; ++x) {
			switch (map[y][x].getType()) {
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