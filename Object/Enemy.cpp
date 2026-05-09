#include <DxLib.h>
#include "Enemy.h"
#include "../framework.h"

namespace {
	const unsigned int DRAW_COLOR = GetColor(245, 20, 20);
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
	if (CheckHitKey(KEY_INPUT_W)) {
		location_.y_ -= vector_.y_;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		location_.y_ += vector_.y_;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		location_.x_ -= vector_.x_;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		location_.x_ += vector_.x_;
	}
}

void Enemy::Draw() {
	DrawCircleAA(location_.x_, location_.y_, DRAW_RADIUS, DRAW_POSNUM, DRAW_COLOR);
}

void Enemy::Release() {
}
