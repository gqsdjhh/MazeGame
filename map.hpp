#pragma once

#include "graphics.h"
#include <vector>

enum class GridType {
	EMPTY,      // 空地
	WALL,       // 墙壁
	START,      // 起点
	END,        // 终点
	TRAP        // 陷阱
};

class Grid {
public:
	Grid(GridType type);
	bool isRoad() const;
	bool isExit() const;
	bool isTrap() const;
	bool isWall() const;
	GridType getType() const;
	void setType(GridType type);
private:
	GridType _type;
};

class Map {
public:
	Map(int width, int height);
	int getWidth() const;
	int getHeight() const;
	const Grid& getMap(int x, int y) const;
	void setGridType(int x, int y, GridType type);
	~Map() = default;
private:
	int _width;
	int _height;
	std::vector<std::vector<Grid>> map;
};

class MapGenerator {
public:
	virtual void generate(Map& map) = 0;
	virtual ~MapGenerator() = default;
};

class EasyMapGenerator : public MapGenerator {
public:
	void generate(Map& map) override;
};

class HardMapGenerator : public MapGenerator {
public:
	void generate(Map& map) override;
};

class MapDisplay {
public:
	virtual void display(const Map& map) = 0;
};

class EasyXMapDisplay : public MapDisplay {
public:
	void display(const Map& map) override;
};
