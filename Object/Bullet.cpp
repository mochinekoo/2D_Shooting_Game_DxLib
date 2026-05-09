#include <DxLib.h>
#include "Bullet.h"
#include "../framework.h"

namespace {
	const unsigned int DRAW_COLOR = GetColor(255, 255, 255);
	const int DRAW_RADIUS = 10;
	const int DRAW_POSNUM = 30;
	const float DEFAULT_SPEED = 5.0f;
}

Bullet::Bullet(const Location3D& location, const Vector3D& vector)
	: BaseObject("Bullet", true) {
	location_ = location;
	vector_ = vector;
}

Bullet::~Bullet() {
}

void Bullet::Init() {
}

void Bullet::Update() {
	location_.x_ += vector_.x_;
	location_.y_ += vector_.y_;
	location_.z_ += vector_.z_;
}

void Bullet::Draw() {
	DrawCircleAA(location_.x_, location_.y_, DRAW_RADIUS, DRAW_POSNUM, DRAW_COLOR);
	DrawCircleAA(location_.x_, location_.y_, DRAW_RADIUS, DRAW_POSNUM + 30, DRAW_COLOR);
}

void Bullet::Release() {
}
