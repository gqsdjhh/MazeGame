#include "graphics.h"
#include "player.hpp"

Player::Player(int x, int y) : _x(x), _y(y) {
	_lives = 3; // 初始生命值
}

std::pair<int, int> Player::GetXY() const {
	return {_x, _y };
}

void Player::Move(int dx, int dy) {
	_x += dx;
	_y += dy;
}

int Player::GetLives() const {
	return _lives;
}

void Player::LoseLife() {
	if (_lives > 0) {
		--_lives;
		NotifyLivesChanged(*this);  // 通知观察者生命值变化

		if (_lives <= 0) {
			NotifyGameOver(false);  // 通知游戏结束（失败）
		}
	}
}

bool Player::IsAlive() {
	return _lives > 0;
}

void Player::PlayerDisplay() const {
	setfillcolor(BLUE);
	fillcircle(_x * 20 + 10, _y * 20 + 10, 8);
}