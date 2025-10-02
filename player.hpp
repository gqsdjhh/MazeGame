#pragma once
#include <utility>

class Player {
public:
	Player(int startX = 1, int startY = 1);
	std::pair<int, int> getXY() const;
	void move(int dx, int dy);
	int getLives() const;
	void loseLife();
	bool isAlive();
	void Playerdisplay() const;
	~Player() = default;
private:
	int _x;
	int _y;
	int _lives;
};
