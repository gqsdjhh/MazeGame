#include "graphics.h"
#include "player.hpp"

// 玩家类构造函数，初始化位置
Player::Player(int x, int y) : _x(x), _y(y) {
	_lives = 3; // 初始生命值
}

// 获取玩家当前坐标
std::pair<int, int> Player::GetXY() const {
	return { _x, _y };
}

// 移动玩家（dx/dy为坐标变化量）
void Player::Move(int dx, int dy) {
	_x += dx;
	_y += dy;
}

// 获取当前生命值
int Player::GetLives() const {
	return _lives;
}

// 减少一条生命
void Player::LoseLife() {
	if (_lives > 0) {
		--_lives;
		NotifyLivesChanged(*this);  // 通知观察者生命值变化

		if (_lives <= 0) {
			NotifyGameOver(false);  // 通知游戏结束（失败）
		}
	}
}

// 判断玩家是否存活
bool Player::IsAlive() {
	return _lives > 0;
}

// 绘制玩家（蓝色圆形）
void Player::PlayerDisplay() const {
	setfillcolor(BLUE);
	fillcircle(_x * 20 + 10, _y * 20 + 10, 8);
}