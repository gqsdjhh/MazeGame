#pragma once

#include "graphics.h"
#include <vector>

enum class GridType {
	EMPTY,      // �յ�
	WALL,       // ǽ��
	START,      // ���
	END,        // �յ�
	TRAP        // ����
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
	~Map();
	void generate();
	void display() const;
private:
	int _width;
	int _height;
	std::vector<std::vector<Grid>> map;
};



