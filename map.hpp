#pragma once

#include "graphics.h"
#include <vector>

enum class GridType {
	EMPTY = 0,      // 空地
	WALL,       // 墙壁
	START,      // 起点
	END,        // 终点
	TRAP        // 陷阱
};

class Grid {
public:
	Grid(GridType type);
	bool IsRoad() const;
	bool IsExit() const;
	bool IsTrap() const;
	bool IsWall() const;
	GridType GetType() const;
	void SetType(GridType type);
	bool IsExplored() const;
	void SetExplored(bool is_explored);
private:
	GridType _type;
	bool _isExplored;
};

class Map {
public:
	Map(int width, int height);
	int GetWidth() const;
	int GetHeight() const;
	Grid& GetMap(int x, int y);
	void SetGridType(int x, int y, GridType type);
	~Map() = default;
private:
	int _width;
	int _height;
	std::vector<std::vector<Grid>> map;
};

class MapGenerator {
public:
	virtual void Generate(Map& map) = 0;
	virtual ~MapGenerator() = default;
};

class EasyMapGenerator : public MapGenerator {
public:
	void Generate(Map& map) override;
};

class HardMapGenerator : public MapGenerator {
public:
	void Generate(Map& map) override;
};

class MapDisplay {
public:
	virtual void Display(Map& map) = 0;
};

class EasyXMapDisplay : public MapDisplay {
public:
	void Display(Map& map) override;
};
