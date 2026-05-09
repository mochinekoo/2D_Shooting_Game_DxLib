#include <DxLib.h>
#include "Enemy.h"
#include "../framework.h"

namespace {
	const unsigned int DRAW_COLOR = GetColor(0, 0, 20);
	const unsigned int LINE_COLOR = GetColor(255, 255, 255);
	const int LINE_SIZE = 10;
	const int DRAW_RADIUS = 30;
	const int DRAW_POSNUM = 30;
	const float DEFAULT_SPEED = 5.0f;
}

Enemy::Enemy()
	: BaseObject("Enemy", true) {
	location_ = Location3D(GameScreen::WIDTH / 2, GameScreen::HEIGHT / 2, 0);
	vector_ = Vector3D(DEFAULT_SPEED, DEFAULT_SPEED, DEFAULT_SPEED);
}

Enemy::~Enemy() {
}

void Enemy::Init() {
}

void Enemy::Update() {
}

void Enemy::Draw() {
	DrawCircleAA(location_.x_, location_.y_, DRAW_RADIUS, DRAW_POSNUM, DRAW_COLOR);
	DrawCircleAA(location_.x_, location_.y_, DRAW_RADIUS, DRAW_POSNUM + LINE_SIZE, LINE_COLOR, FALSE);
}

void Enemy::Release() {
}
