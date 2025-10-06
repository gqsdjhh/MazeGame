#include "graphics.h"
#include "player.hpp"

// ����๹�캯������ʼ��λ��
Player::Player(int x, int y) : _x(x), _y(y) {
	_lives = 3; // ��ʼ����ֵ
}

// ��ȡ��ҵ�ǰ����
std::pair<int, int> Player::GetXY() const {
	return { _x, _y };
}

// �ƶ���ң�dx/dyΪ����仯����
void Player::Move(int dx, int dy) {
	_x += dx;
	_y += dy;
}

// ��ȡ��ǰ����ֵ
int Player::GetLives() const {
	return _lives;
}

// ����һ������
void Player::LoseLife() {
	if (_lives > 0) {
		--_lives;
		NotifyLivesChanged(*this);  // ֪ͨ�۲�������ֵ�仯

		if (_lives <= 0) {
			NotifyGameOver(false);  // ֪ͨ��Ϸ������ʧ�ܣ�
		}
	}
}

// �ж�����Ƿ���
bool Player::IsAlive() {
	return _lives > 0;
}

// ������ң���ɫԲ�Σ�
void Player::PlayerDisplay() const {
	setfillcolor(BLUE);
	fillcircle(_x * 20 + 10, _y * 20 + 10, 8);
}