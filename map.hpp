#pragma once

#include "graphics.h"
#include <vector>

// ��������ö��
enum class GridType {
	EMPTY = 0,      // �յ�
	WALL,           // ǽ��
	START,          // ���
	END,            // �յ�
	TRAP            // ����
};

// ����Ԫ��
class Grid {
public:
	Grid(GridType type);       // ���캯������ʼ����������
	bool IsRoad() const;       // �ж��Ƿ�Ϊ��ͨ�����򣨿յ�/���/�յ㣩
	bool IsExit() const;       // �ж��Ƿ�Ϊ�յ�
	bool IsTrap() const;       // �ж��Ƿ�Ϊ����
	bool IsWall() const;       // �ж��Ƿ�Ϊǽ��
	GridType GetType() const;  // ��ȡ��������
	void SetType(GridType type); // ������������
	bool IsExplored() const;   // �ж��Ƿ���̽��
	void SetExplored(bool is_explored); // ����̽��״̬

private:
	GridType _type;        // ��������
	bool _isExplored;      // ̽��״̬���
};

// ��ͼ��
class Map {
public:
	Map(int width, int height); // ���캯������ʼ����ͼ�ߴ�
	~Map() = default;

	int GetWidth() const;       // ��ȡ��ͼ���
	int GetHeight() const;      // ��ȡ��ͼ�߶�
	Grid& GetMap(int x, int y); // ��ȡָ�����������
	void SetGridType(int x, int y, GridType type); // ����ָ���������������

private:
	int _width;                   // ��ͼ���
	int _height;                  // ��ͼ�߶�
	std::vector<std::vector<Grid>> map; // �����ά����
};

// ��ͼ����������
class MapGenerator {
public:
	virtual void Generate(Map& map) = 0; // ���ɵ�ͼ�����麯����
	virtual ~MapGenerator() = default;
};

// �򵥵�ͼ������
class EasyMapGenerator : public MapGenerator {
public:
	void Generate(Map& map) override; // ���ɼ��Ѷȵ�ͼ
};

// ���ѵ�ͼ������
class HardMapGenerator : public MapGenerator {
public:
	void Generate(Map& map) override; // ���������Ѷȵ�ͼ
};

// ��ͼ��ʾ������
class MapDisplay {
public:
	virtual void Display(Map& map) = 0; // ��ʾ��ͼ�����麯����
};

// EasyX���ͼ��ʾ��
class EasyXMapDisplay : public MapDisplay {
public:
	void Display(Map& map) override; // ʹ��EasyX����ʾ��ͼ
};